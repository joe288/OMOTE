#include <map>
#include "scenes/scene_TV.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
#include "devices/AVreceiver/device_VU/device_VU.h"
#include "applicationInternal/commandHandler.h"
#include "devices/misc/device_smarthome/device_smarthome.h"
// guis
#include "guis/gui_numpad.h"

uint16_t SCENE_TV         ; //"Scene_tv"
uint16_t SCENE_TV_FORCE   ; //"Scene_tv_force"

std::map<char, repeatModes> key_repeatModes_TV;
std::map<char, uint16_t> key_commands_short_TV;
std::map<char, uint16_t> key_commands_long_TV;

void scene_setKeys_TV() {
  key_repeatModes_TV = {
    {KEY_STOP,  SHORT_REPEATED   },
    {KEY_REWI,  SHORT            },
    {KEY_PLAY,  SHORT            },
    {KEY_FORW,  SHORT_REPEATED   },
    {KEY_CONF,  SHORT            },
    {KEY_INFO,  SHORT            },
                                                         {KEY_UP,    SHORT_REPEATED   },
    {KEY_LEFT,  SHORT_REPEATED   },
    {KEY_OK,    SHORT            },
    {KEY_RIGHT, SHORT_REPEATED   },
                                                         {KEY_DOWN,  SHORT_REPEATED   },
                                                                                                             {KEY_SRC,   SHORT            },
                                                                                                             {KEY_CHUP,  SHORT            },
                                                                                                             {KEY_CHDOW, SHORT            },
  };
  
  key_commands_short_TV = {
    {KEY_STOP,  VU_STOP           },
    {KEY_REWI,  VU_BACK           },
    {KEY_PLAY,  VU_PLAY_PAUSE     },
    {KEY_FORW,  VU_FORWARD        },
    {KEY_CONF,  VU_CONTXT         },
    {KEY_INFO,  VU_MENU           },
    {KEY_UP,    VU_SETMENU_UP     },
    {KEY_LEFT,  VU_SETMENU_LEFT   },
    {KEY_OK,    VU_OK             },
    {KEY_RIGHT, VU_SETMENU_RIGHT  },
    {KEY_DOWN,  VU_SETMENU_DOWN   },
    {KEY_SRC,   VU_EXIT           },
    {KEY_CHUP,  VU_PROG_PLUS      },
    {KEY_CHDOW, VU_PROG_MINUS     },
    {KEY_REC,   VU_RECORD         },
    {KEY_RED,   VU_RED            },
    {KEY_GREEN, VU_GREEN          },
    {KEY_BLUE,  VU_BLUE           },
    {KEY_REC,   VU_RECORD         },
    {KEY_BACK,  VU_EPG            },
    {KEY_MUTE,  VU_MUTE_TOGGLE    },
    {KEY_VOLDO, VU_VOL_MINUS      },
    {KEY_VOLUP, VU_VOL_PLUS       },
    //VU_BACK
  };
  
  key_commands_long_TV = {
  };

}

void scene_start_sequence_TV(void) {
  executeCommand(SMARTHOME_OMOTE_VU_ENABLE,"false");
  delay(500);
  executeCommand(SMARTHOME_OMOTE_VU_ENABLE,"true");
}

void scene_end_sequence_TV(void) {

}

std::string scene_name_TV = "TV";
t_gui_list scene_TV_gui_list = {tabName_numpad};

void register_scene_TV(void) {
  register_command(&SCENE_TV,       makeCommandData(SCENE, {scene_name_TV}));
  register_command(&SCENE_TV_FORCE, makeCommandData(SCENE, {scene_name_TV, "FORCE"}));

  register_scene(
    scene_name_TV,
    & scene_setKeys_TV,
    & scene_start_sequence_TV,
    & scene_end_sequence_TV,
    & key_repeatModes_TV,
    & key_commands_short_TV,
    & key_commands_long_TV,
    & scene_TV_gui_list,
    SCENE_TV);
}
