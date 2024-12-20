#include <map>
#include "scenes/scene_Playstation.h"
#include "devices/mediaPlayer/device_playstation/gui_playstation.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
#include "devices/misc/device_smarthome/device_smarthome.h"
#include "devices/AVreceiver/device_VU/device_VU.h"
#include "applicationInternal/commandHandler.h"
// guis
#include "guis/gui_numpad.h"

uint16_t SCENE_PLAYSTATION; 
uint16_t SCENE_SCENE_PLAYSTATION_FORCE;

std::map<char, repeatModes> key_repeatModes_Playstation;
std::map<char, uint16_t> key_commands_short_Playstation;
std::map<char, uint16_t> key_commands_long_Playstation;

void scene_setKeys_Playstation() {
//   key_repeatModes_Playstation = {
//     {KEY_REWI,  SHORTorLONG      },
//     {KEY_PLAY,  SHORT            },
//     {KEY_FORW,  SHORTorLONG      },
//     {KEY_CONF,  SHORT            },
//     {KEY_INFO,  SHORT            },
//     {KEY_UP,    SHORT            },
//     {KEY_LEFT,  SHORT            },
//     {KEY_OK,    SHORT            },
//     {KEY_RIGHT, SHORT            },
//     {KEY_DOWN,  SHORT            },
//     {KEY_SRC,   SHORT            },
//   };
  
//   key_commands_short_Playstation = {
//     {KEY_REWI,  KEYBOARD_REWIND  },
//     {KEY_PLAY, KEYBOARD_PLAYPAUSE},   
//     {KEY_FORW,  KEYBOARD_FASTFORWARD},
//     {KEY_CONF,  KEYBOARD_HOME    },  
//     {KEY_INFO,  KEYBOARD_MENU    },
//     {KEY_UP,    KEYBOARD_UP      },
//     {KEY_LEFT,  KEYBOARD_LEFT    },
//     {KEY_OK,    KEYBOARD_SELECT  },
//     {KEY_RIGHT, KEYBOARD_RIGHT   },
//     {KEY_DOWN,  KEYBOARD_DOWN    },
//     {KEY_SRC,   KEYBOARD_BACK    },
//   };
  
//   key_commands_long_Playstation = {
//     {KEY_REWI,  KEYBOARD_REWIND_LONG},
//     {KEY_FORW,  KEYBOARD_FASTFORWARD_LONG},
//   };

}

void scene_start_sequence_Playstation(void) {
  executeCommand(SMARTHOME_OMOTE_VU_ENABLE,"false");
  delay(500);
  executeCommand(SMARTHOME_OMOTE_VU_ENABLE,"true");
  delay(500);
  executeCommand(VU_KEY5);
  executeCommand(VU_KEY0);
  executeCommand(VU_OK);
}

void scene_end_sequence_Playstation(void) {
  executeCommand(VU_KEY1);
  executeCommand(VU_OK);
}

std::string scene_name_Playstation = "Playstation";
// t_gui_list scene_Playstation_gui_list = {tabName_playstation};
t_gui_list scene_Playstation_gui_list = {tabName_playstation};

void register_scene_Playstation(void) {
  register_command(&SCENE_PLAYSTATION,       makeCommandData(SCENE, {scene_name_Playstation}));
  register_command(&SCENE_SCENE_PLAYSTATION_FORCE, makeCommandData(SCENE, {scene_name_Playstation, "FORCE"}));

  register_scene(
    scene_name_Playstation,
    & scene_setKeys_Playstation,
    & scene_start_sequence_Playstation,
    & scene_end_sequence_Playstation,
    & key_repeatModes_Playstation,
    & key_commands_short_Playstation,
    & key_commands_long_Playstation,
    & scene_Playstation_gui_list,
    SCENE_PLAYSTATION);
}
