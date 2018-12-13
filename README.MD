ESP32-MICRONES, a Nintendo Entertainment System emulator for the ESP32
====================================================================

![MicroNES](https://raw.githubusercontent.com/pebri86/esp32-micrones/master/hardware/image1.png)

This is a port of Nofrendo, a Nintendo Entertainment System emulator. This port is based on Sprite_tm ESP32-NESEMU and is entirely unsupported by Espressif. The code is adapted to my hardware configuration using cheap 160x128 1,8" ST7735R SPI display or ILI9341 (configurable via menuconfig), NES video are scaled to fit display resolution using a simple image scaling alghoritm "smooth Bresenham scaling". Some text maybe hard to read due to scaling but most of rom text are readable.

Compiling
---------

This code is an esp-idf project. You will need esp-idf to compile it. Newer versions of esp-idf may introduce incompatibilities with this code;
for your reference, the code was tested against release/v3.2 branch of esp-idf.


Display
-------

To display the NES output, please connect a 160x128 1,8" ST7735R or ILI9341 SPI display to the ESP32 in this way:

    Pin | GPIO
    --- | ----
    MOSI/SDA | 23
    CLK | 19
    CS | 22
    DC | 5
    RST | 18
    BCKL | 17

(BCKL = backlight enable - PWM Controlled)

Also connect the power supply and ground. For now, the LCD is controlled using a DMA controller and fed to 2nd CPU. You can change different layout of lcd pins and type of LCD using menuconfig to adapt your hardware configuration, just select custom hardware on menuconfig and change your pins settings. If you have another type of spi lcd display write your own driver and place in driver folder, adjust the code to use your newly created lcd driver. please notify me if you write your own driver so i can add in the repo.


Controller
----------

To control the NES, connect GPIO pins to a common ground pcb gamepad:

    Key | GPIO
    --- | ----
    A | 0
    B | 4
    START | 12
    SELECT | 14
    RIGHT | 27
    DOWN | 25
    UP | 33
    LEFT | 32
    MENU | 2

Also connect the ground line. Same like lcd pins you can change different layout of gamepad pins via menuconfig.

ROM
---

This includes no Roms. You'll have to flash your own Roms and modify the roms.txt according to your needs.
Don't change the Layout from roms.txt, otherwise it could happen, that the menu will not load.
Description on how to change the roms.txt and where to place the Roms are in the file itself.

You can flash up to 13 Roms.
* 4x up to 100KB
* 2x up to 132KB
* 3x up to 260KB
* 1x up to 296KB, 388KB, 516KB, 772KB,

Flash the Roms with the flashrom.sh script, you'll need to add an argument for flash adress(0x12345) and one for the
file you want to flash: ./flashrom.sh 0xTargetAdress RomName.nes
Flash the roms.txt with the flashtxt.sh script: ./flashtxt roms.txt

If you flash, for example, only to Rom-Partition 2, you'll have to give Rom1 in roms.txt anyhow an Name (a place-maker)
otherwise the menu couldn't load the right partition.

User Interface Navigation
-------------------------

On startup you'll serve by Screen Tab View and some info on header clock and battery info (still dummy due to my hardware prototype doesn't have yet RTC for clock and battery sense).

* use select button to set focus on the ui components, each press will rolling focus on tab -> list -> other components just hit this button until your desired selected ui component get highlighted.
* use nav button (up down or left right) to scroll on list, select between two tabs, or change slider on settings page.
* use A button to select game on the list, to hit save button in the settings tab, or select the tab view to settings/game list.

use menu button to back to ui interface when playing game (actually this button get esp32 to restart).

Contribute
----------

You can freely fork and modify the code, or contribute your modified code. just contact me at pebri86@gmail.com.

Copyright
---------

* Code in this repository is Copyright (C) 2016 Espressif Systems, licensed under the Apache License 2.0 as described in the file LICENSE.
* Code in the components/nofrendo is Copyright (c) 1998-2000 Matthew Conte (matt@conte.com) and licensed under the GPLv2.
* Code in the components/lvgl is MIT licence Copyright (c) 2016 Gábor Kiss-Vámosi Open Source Graphics Library For Embedded https://github.com/littlevgl/lvgl.
* Some code adapted from https://github.com/MittisBootloop/esp32_nesemu_wemosmini, and Odroid Go sources, thanks.