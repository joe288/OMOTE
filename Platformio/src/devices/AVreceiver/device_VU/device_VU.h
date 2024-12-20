#pragma once

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
extern uint16_t VU_RADIO;
extern uint16_t VU_TV;
extern uint16_t VU_CONTXT;
extern uint16_t VU_HELP;
extern uint16_t VU_RECORD;
extern uint16_t VU_EPG;
extern uint16_t VU_EXIT;
extern uint16_t VU_AUDIO;
extern uint16_t VU_KEYRIGHT;
extern uint16_t VU_KEYLEFT;
extern uint16_t VU_KEY9;
extern uint16_t VU_KEY8;
extern uint16_t VU_KEY7;
extern uint16_t VU_KEY6;
extern uint16_t VU_KEY5;
extern uint16_t VU_KEY4;
extern uint16_t VU_KEY3;
extern uint16_t VU_KEY2;
extern uint16_t VU_KEY1;
extern uint16_t VU_KEY0;
extern uint16_t VU_PLAY_PAUSE;
extern uint16_t VU_STOP;
extern uint16_t VU_FORWARD;
extern uint16_t VU_BACK;
extern uint16_t VU_BLUE;
extern uint16_t VU_GREEN;
extern uint16_t VU_YELLOW;
extern uint16_t VU_RED;
extern uint16_t VU_VOL_MINUS;
extern uint16_t VU_VOL_PLUS;
extern uint16_t VU_PROG_MINUS;
extern uint16_t VU_PROG_PLUS;
extern uint16_t VU_PROG_PLUS2;
extern uint16_t VU_MUTE_TOGGLE;
extern uint16_t VU_OK;
extern uint16_t VU_SETMENU_UP;
extern uint16_t VU_SETMENU_DOWN;
extern uint16_t VU_SETMENU_RIGHT;
extern uint16_t VU_SETMENU_LEFT;
extern uint16_t VU_MENU;
extern uint16_t VU_POWER_TOGGLE;
extern uint16_t TV_POWER_TOGGLE;

void register_device_VU();
