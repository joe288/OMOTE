#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_VU.h"

  // Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
  uint16_t VU_RADIO               ;
  uint16_t VU_TV                  ;
  uint16_t VU_CONTXT              ;
  uint16_t VU_HELP                ;
  uint16_t VU_RECORD              ;
  uint16_t VU_EPG                 ;
  uint16_t VU_EXIT                ;
  uint16_t VU_AUDIO               ;
  uint16_t VU_KEYRIGHT            ;
  uint16_t VU_KEYLEFT             ;
  uint16_t VU_KEY9                ;
  uint16_t VU_KEY8                ;
  uint16_t VU_KEY7                ;
  uint16_t VU_KEY6                ;
  uint16_t VU_KEY5                ;
  uint16_t VU_KEY4                ;
  uint16_t VU_KEY3                ;
  uint16_t VU_KEY2                ;
  uint16_t VU_KEY1                ;
  uint16_t VU_KEY0                ;
  uint16_t VU_PLAY_PAUSE          ;
  uint16_t VU_STOP                ;
  uint16_t VU_FORWARD             ;
  uint16_t VU_BACK                ;
  uint16_t VU_RED                 ;
  uint16_t VU_YELLOW              ; 
  uint16_t VU_GREEN               ; 
  uint16_t VU_BLUE                ; 
  uint16_t VU_VOL_MINUS           ; 
  uint16_t VU_VOL_PLUS            ; 
  uint16_t VU_PROG_MINUS          ; 
  uint16_t VU_PROG_PLUS           ; 
  uint16_t VU_MUTE_TOGGLE         ;
  uint16_t VU_OK                  ;
  uint16_t VU_SETMENU_UP          ;
  uint16_t VU_SETMENU_DOWN        ;
  uint16_t VU_SETMENU_RIGHT       ;
  uint16_t VU_SETMENU_LEFT        ;
  uint16_t VU_MENU                ;
  uint16_t VU_POWER_TOGGLE        ;
  uint16_t TV_POWER_TOGGLE        ;

void register_device_VU() {
  // tested with VU+ DUO4K, works also with others

  // Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
  register_command(&VU_RADIO               , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC805290F2"}));
  register_command(&VU_TV                  , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC805290E4"}));
  register_command(&VU_CONTXT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80521049"}));
  register_command(&VU_HELP                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529081"}));
  register_command(&VU_RECORD              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529037"}));
  register_command(&VU_EPG                 , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC805290CC"}));
  register_command(&VU_EXIT                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529055"}));
  register_command(&VU_AUDIO               , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC805290E5"}));
  register_command(&VU_KEYLEFT             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC805290BB"}));
  register_command(&VU_KEYRIGHT            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC805290BC"}));
  register_command(&VU_KEY9                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529009"}));
  register_command(&VU_KEY8                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529008"}));
  register_command(&VU_KEY7                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529007"}));
  register_command(&VU_KEY6                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529006"}));
  register_command(&VU_KEY5                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529005"}));
  register_command(&VU_KEY4                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529004"}));
  register_command(&VU_KEY3                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529003"}));
  register_command(&VU_KEY2                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529002"}));
  register_command(&VU_KEY1                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529001"}));
  register_command(&VU_KEY0                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529000"}));
  register_command(&VU_PLAY_PAUSE          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052902D"}));
  register_command(&VU_STOP                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529031"}));
  register_command(&VU_FORWARD             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529028"}));
  register_command(&VU_BACK                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529029"}));
  register_command(&VU_RED                 , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052906D"}));
  register_command(&VU_YELLOW              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052906F"}));
  register_command(&VU_GREEN               , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052906E"}));
  register_command(&VU_BLUE                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529070"}));
  register_command(&VU_VOL_MINUS           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80521011"}));
  register_command(&VU_VOL_PLUS            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80521010"}));
  register_command(&VU_PROG_MINUS          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529021"}));
  register_command(&VU_PROG_PLUS           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529020"}));
  register_command(&VU_MUTE_TOGGLE         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052900D"}));
  register_command(&VU_OK                  , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052905C"}));
  register_command(&VU_SETMENU_UP          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529058"}));
  register_command(&VU_SETMENU_DOWN        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80529059"}));
  register_command(&VU_SETMENU_LEFT        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052105A"}));
  register_command(&VU_SETMENU_RIGHT       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052905B"}));
  register_command(&VU_MENU                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC80521054"}));
  register_command(&VU_POWER_TOGGLE        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC6), "0xC8052900C"}));
  register_command(&TV_POWER_TOGGLE        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_RC5), "0x80C"}));
}
