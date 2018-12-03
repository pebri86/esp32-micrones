#ifndef GAMEPAD_H
#define GAMEPAD_H

#define A       CONFIG_GAMEPAD_A
#define B       CONFIG_GAMEPAD_B
#define START   CONFIG_GAMEPAD_START
#define SELECT  CONFIG_GAMEPAD_SELECT
#define UP      CONFIG_GAMEPAD_UP
#define DOWN    CONFIG_GAMEPAD_DOWN
#define LEFT    CONFIG_GAMEPAD_LEFT
#define RIGHT   CONFIG_GAMEPAD_RIGHT

enum
{
	GAMEPAD_INPUT_UP = 0,
    GAMEPAD_INPUT_RIGHT,
    GAMEPAD_INPUT_DOWN,
    GAMEPAD_INPUT_LEFT,
    GAMEPAD_INPUT_SELECT,
    GAMEPAD_INPUT_START,
    GAMEPAD_INPUT_A,
    GAMEPAD_INPUT_B,

	GAMEPAD_INPUT_MAX
};

typedef struct
{
    uint8_t values[GAMEPAD_INPUT_MAX];
} gamepad_state;

gamepad_state gamepad_input_read_raw();
void gamepad_read(gamepad_state* out_state);
void gamepad_init();

#endif
