#include <lvgl.h>
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/keys.h"
#include "devices/misc/device_smarthome/gui_smarthome.h"
#include "devices/misc/device_smarthome/device_smarthome.h"
#include "scenes/scene__default.h"

// LVGL declarations
LV_IMG_DECLARE(lightbulb);

uint16_t GUI_SMARTHOME_ACTIVATE;

std::map<char, repeatModes> key_repeatModes_smarthome = {};
std::map<char, uint16_t> key_commands_short_smarthome = {};
std::map<char, uint16_t> key_commands_long_smarthome = {};

// Smart Home Toggle Event handler

static void button_clicked_event_cb(lv_event_t* e) {
  int user_data = (intptr_t)(e->user_data);
  switch (user_data)
  {
  case 0:
      executeCommand(SMARTHOME_MQTT_LICHT_LINKS,"toggle");
    break;
  case 1:
      executeCommand(SMARTHOME_MQTT_LICHT_MITTE,"toggle");
    break;
  case 2:
      executeCommand(SMARTHOME_MQTT_LICHT_RECHTS,"toggle");
    break;
  case 3:
      executeCommand(SMARTHOME_MQTT_LICHT_COUTCH,"toggle");
    break;
  case 4:
      executeCommand(SMARTHOME_MQTT_LICHT_ESSEN,"toggle");
    break;
  default:
    break;
  }  
}

void createLight(lv_obj_t* parent, const char * text, uint8_t index){
  lv_obj_t* menuBox = lv_obj_create(parent);
  lv_obj_set_size(menuBox, lv_pct(100), 55);
  lv_obj_set_style_bg_color(menuBox, color_primary, LV_PART_MAIN);
  lv_obj_set_style_border_width(menuBox, 0, LV_PART_MAIN);

  lv_obj_t* bulbIcon = lv_img_create(menuBox);
  lv_img_set_src(bulbIcon, &lightbulb);
  lv_obj_set_style_img_recolor(bulbIcon, lv_color_white(), LV_PART_MAIN);
  lv_obj_set_style_img_recolor_opa(bulbIcon, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_align(bulbIcon, LV_ALIGN_TOP_LEFT, 0, 0);

  lv_obj_t* menuLabel = lv_label_create(menuBox);
  lv_label_set_text(menuLabel, text);
  lv_obj_align(menuLabel, LV_ALIGN_TOP_LEFT, 22, 3);

  // -- create a button
  lv_obj_t* button = lv_btn_create(menuBox);
  lv_obj_set_size(button, 80, 28);
  lv_obj_align(button, LV_ALIGN_TOP_RIGHT, 0, 0);
  lv_obj_set_style_radius(button, 5, LV_PART_MAIN);
  lv_obj_set_style_bg_color(button, lv_color_lighten(color_primary, 100), LV_PART_MAIN);
  lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t) index);

  lv_obj_t* label = lv_label_create(button);
  lv_label_set_text(label, "ON/OFF");
  lv_obj_center(label);
}

void create_tab_content_smarthome(lv_obj_t* tab) {

  // Add content to the smart home tab
  lv_obj_set_layout(tab, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(tab, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_scrollbar_mode(tab, LV_SCROLLBAR_MODE_ACTIVE);

  // Add a tab
  lv_obj_t* menuLabel = lv_label_create(tab);
  lv_label_set_text(menuLabel, "Licht");

  createLight(tab, "links"   , 0);
  createLight(tab, "mitte"   , 1);
  createLight(tab, "rechts"  , 2);
  createLight(tab, "Coutch"  , 3);
  createLight(tab, "Essen"   , 4);
}

void notify_tab_before_delete_smarthome(void) {
}

void gui_setKeys_smarthome() {
  key_commands_short_smarthome = {
    {KEY_STOP, SCENE_SELECTION},
  };
}

void register_gui_smarthome(void){

  register_gui(
    std::string(tabName_smarthome),
    & create_tab_content_smarthome,
    & notify_tab_before_delete_smarthome,
    & gui_setKeys_smarthome,
    & key_repeatModes_smarthome,
    & key_commands_short_smarthome,
    & key_commands_long_smarthome
    );

  register_command(&GUI_SMARTHOME_ACTIVATE, makeCommandData(GUI, {std::to_string(MAIN_GUI_LIST), std::string(tabName_smarthome)}));
}
