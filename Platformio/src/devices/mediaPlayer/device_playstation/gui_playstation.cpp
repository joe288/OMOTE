#include <lvgl.h>
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/omote_log.h"
#include "devices/mediaPlayer/device_playstation/gui_playstation.h"

#include "applicationInternal/commandHandler.h"
#include "devices/mediaPlayer/device_playstation/device_playstation.h"

// LVGL declarations
LV_IMG_DECLARE(playstationIcon);

// playstation Key Event handler
static void playstationKey_event_cb(lv_event_t* e) {
  // Send IR command based on the event user data  
  int user_data = *((int*)(&(e->user_data)));
  executeCommand(PLAYSTATION_GUI_EVENT_USER_DATA, std::to_string(50 + user_data));
  omote_log_v("%d\r\n", 50 + user_data);
}

void create_tab_content_playstation(lv_obj_t* tab) {

  // Add content to the playstation tab
  // Add a nice playstation logo

  lv_obj_t* playstationImg = lv_img_create(tab);
  lv_img_set_src(playstationImg, &playstationIcon);
  lv_obj_align(playstationImg, LV_ALIGN_CENTER, 0, 0);
}

void notify_tab_before_delete_playstation(void) {
  // remember to set all pointers to lvgl objects to NULL if they might be accessed from outside.
  // They must check if object is NULL and must not use it if so

}

void register_gui_playstation(void){
  register_gui(std::string(tabName_playstation), & create_tab_content_playstation, & notify_tab_before_delete_playstation);
}
