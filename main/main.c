#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "nofrendo.h"
#include "esp_partition.h"
#include "esp_spiffs.h"

#include "esp_err.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"
#include <dirent.h>


#include "settings.h"
#include "power.h"
#include "sdcard.h"
#include "display.h"
#include "gamepad.h"
#include "audio.h"
#include "ui.h"

const char* SD_BASE_PATH = "/sd";
static char* ROM_DATA = (char*)0x3f800000;

char *osd_getromdata()
{
    printf("Initialized. ROM@%p\n", ROM_DATA);
    return (char*)ROM_DATA;
}


static const char *TAG = "main";


int app_main(void)
{
    printf("nesemu (%s-%s).\n", COMPILEDATE, GITREV);

    nvs_flash_init();

    system_init();

    esp_err_t ret;


    char* fileName;

    char* romName = get_rom_name_settings();
    if (romName)
    {
        fileName = system_util_GetFileName(romName);
        if (!fileName) abort();

        free(romName);
    }
    else
    {
        fileName = "nesemu-show3.nes";
    }


    int startHeap = esp_get_free_heap_size();
    printf("A HEAP:0x%x\n", startHeap);


    display_init();

    // Joystick.
    gamepad_init();

    display_prepare();

    set_display_brightness(get_backlight_settings());

    display_show_splash();
    vTaskDelay(1000);

    // ui init
    if(!gpio_get_level(MENU) || get_menu_flag_settings() == 1)
    {
      ui_init();

      while(true)
      {
        vTaskDelay(100);
      }
    }

    // Load ROM
    char* romPath = get_rom_name_settings();
    if (!romPath)
    {
        printf("osd_getromdata: Reading from flash.\n");

        // copy from flash
        spi_flash_mmap_handle_t hrom;

        const esp_partition_t* part = esp_partition_find_first(0x40, 0, NULL);
        if (part == 0)
        {
            printf("esp_partition_find_first failed.\n");
            abort();
        }

        esp_err_t err = esp_partition_read(part, 0, (void*)ROM_DATA, 0x100000);
        if (err != ESP_OK)
        {
            printf("esp_partition_read failed. size = %x (%d)\n", part->size, err);
            abort();
        }
    }
    else
    {
        printf("osd_getromdata: Reading from sdcard.\n");

        // copy from SD card
        esp_err_t r = sdcard_open(SD_BASE_PATH);
        if (r != ESP_OK)
        {
            abort();
        }

        display_clear(0);
        display_show_hourglass();
        size_t fileSize = sdcard_copy_file_to_memory(romPath, ROM_DATA);
        printf("app_main: fileSize=%d\n", fileSize);
        if (fileSize == 0)
        {
            abort();
        }

        r = sdcard_close();
        if (r != ESP_OK)
        {
            abort();
        }

        free(romPath);
    }


    printf("NoFrendo start!\n");

    char* args[1] = { fileName };
    nofrendo_main(1, args);

    printf("NoFrendo died.\n");
    asm("break.n 1");
    return 0;
}