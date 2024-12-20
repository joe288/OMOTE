#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/keys.h"
#include "devices/misc/device_smarthome/gui_smarthome_Rollo.h"
#include "devices/misc/device_smarthome/device_smarthome.h"
#include "scenes/scene__default.h"

// LVGL declarations
LV_IMG_DECLARE(jalousie);

uint16_t GUI_SMARTHOME_ROLLO_ACTIVATE;

std::map<char, repeatModes> key_repeatModes_smarthome_Rollo = {};
std::map<char, uint16_t> key_commands_short_smarthome_Rollo = {};
std::map<char, uint16_t> key_commands_long_smarthome_Rollo = {};

// Smart Home Toggle Event handler
static void timout_event_cb(lv_event_t* e){
  lv_obj_t* drop = lv_event_get_target(e);
  int user_data = (intptr_t)(e->user_data);
  char buffer[30];
  switch (user_data)
  {
  case 10: 
    sprintf(buffer,"set WZ_Rollo_Strasse pct %d",(lv_dropdown_get_selected(drop)*10));
    break;
  case 20: 
    sprintf(buffer,"set WZ_Rollo_gross pct %d",(lv_dropdown_get_selected(drop)*10));
    break;
  case 30: 
    sprintf(buffer,"set WZ_Rollo_Tuer pct %d",(lv_dropdown_get_selected(drop)*10));
    break;
  case 40: 
    sprintf(buffer,"set WZ_Rollo_fest pct %d",(lv_dropdown_get_selected(drop)*10));
    break;
  default:
    break;
  }
  executeCommand(SMARTHOME_MQTT_FHEM,buffer);
}

void createRollo(lv_obj_t * parent, const char * text, uint8_t index) {
  lv_obj_t* menuBox = lv_obj_create(parent);
  lv_obj_set_size(menuBox, lv_pct(100), 68);
  lv_obj_set_style_bg_color(menuBox, color_primary, LV_PART_MAIN);
  lv_obj_set_style_border_width(menuBox, 0, LV_PART_MAIN);

  lv_obj_t* rolloIcon = lv_img_create(menuBox);
  lv_img_set_src(rolloIcon, &jalousie);
  lv_obj_set_style_img_recolor(rolloIcon, lv_color_white(), LV_PART_MAIN);
  lv_obj_set_style_img_recolor_opa(rolloIcon, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_align(rolloIcon, LV_ALIGN_TOP_LEFT, 0, 0);  

  lv_obj_t* menuLabel = lv_label_create(menuBox);
  lv_label_set_text(menuLabel, text);
  lv_obj_align(menuLabel, LV_ALIGN_TOP_MID, 22, 0);
  
  // -- create a Dropdown
  lv_obj_t* drop = lv_dropdown_create(menuBox);
  lv_dropdown_set_options(drop, "0\n"
                                "10\n"
                                "20\n"
                                "30\n"
                                "40\n"
                                "50\n"
                                "60\n"
                                "70\n"
                                "80\n"
                                "90\n"
                                "100");
  lv_dropdown_set_selected_highlight(drop, true);
  lv_obj_align(drop, LV_ALIGN_TOP_RIGHT, 0, 20);
  lv_obj_set_size(drop, 70, 22);
  lv_obj_set_style_pad_top(drop, 1, LV_PART_MAIN);
  lv_obj_set_style_bg_color(drop, color_primary, LV_PART_MAIN);
  lv_obj_set_style_bg_color(lv_dropdown_get_list(drop), color_primary, LV_PART_MAIN);
  lv_obj_set_style_border_width(lv_dropdown_get_list(drop), 1, LV_PART_MAIN);
  lv_obj_set_style_border_color(lv_dropdown_get_list(drop), lv_color_hex(0x505050), LV_PART_MAIN);
  lv_obj_add_event_cb(drop, timout_event_cb, LV_EVENT_VALUE_CHANGED, (void *)(intptr_t) index);
}

void create_tab_content_smarthome_Rollo(lv_obj_t* tab) {

  // Add content to the smart home tab
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);

  // Add another tab
  lv_obj_t* menuLabel = lv_label_create(tab);
  lv_label_set_text(menuLabel, "Rollo");

  createRollo(tab, "Strasse", 10);
  createRollo(tab, "Gross",   20);
  createRollo(tab, "Tuer",    30);
  createRollo(tab, "Fest",    40);
}

void notify_tab_before_delete_smarthome_Rollo(void) {
}

void gui_setKeys_smarthome_Rollo() {
  key_commands_short_smarthome_Rollo = {
    {KEY_STOP, SCENE_SELECTION},
  };
}

void register_gui_smarthome_Rollo(void){

  register_gui(
    std::string(tabName_smarthome_Rollo),
    & create_tab_content_smarthome_Rollo,
    & notify_tab_before_delete_smarthome_Rollo,
    & gui_setKeys_smarthome_Rollo,
    & key_repeatModes_smarthome_Rollo,
    & key_commands_short_smarthome_Rollo,
    & key_commands_long_smarthome_Rollo
    );

  register_command(&GUI_SMARTHOME_ROLLO_ACTIVATE, makeCommandData(GUI, {std::to_string(MAIN_GUI_LIST), std::string(tabName_smarthome_Rollo)}));
}
