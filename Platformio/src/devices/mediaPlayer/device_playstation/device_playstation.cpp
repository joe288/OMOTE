#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_playstation.h"

uint16_t PLAYSTATION_GUI_EVENT_USER_DATA; //"playstation_gui_event_user_data";

void register_device_playstation() {
  // register_command(&PLAYSTATION_GUI_EVENT_USER_DATA           , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY)}));  // payload must be set when calling commandHandler
}
