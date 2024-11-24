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
LV_IMG_DECLARE(jalousie);

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
  case 11: //down
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_Strasse closed");
    break;
  case 12: //stop
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_Strasse stop");
    break;
  case 13: //up
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_Strasse open");
    break;
  case 21: //down
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_gross closed");
    break;
  case 22: //stop
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_gross stop");
    break;
  case 23: //up
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_gross open");
    break;
  case 31: //down
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_Tuer closed");
    break;
  case 32: //stop
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_Tuer stop");
    break;
  case 33: //up
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_Tuer open");
    break;
  case 41: //down
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_fest closed");
    break;
  case 42: //stop
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_fest stop");
    break;
  case 43: //up
      executeCommand(SMARTHOME_MQTT_FHEM,"set WZ_Rollo_fest open");
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

void createRollo(lv_obj_t * parent, const char * text, uint8_t index) {
  lv_obj_t* menuBox = lv_obj_create(parent);
  lv_obj_set_size(menuBox, lv_pct(100), 74);
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

  // -- create a button Down
  lv_obj_t* button = lv_btn_create(menuBox);
  lv_obj_set_size(button, 28, 28);
  lv_obj_align(button, LV_ALIGN_TOP_RIGHT, -100, 20);
  lv_obj_set_style_radius(button, 5, LV_PART_MAIN);
  lv_obj_set_style_bg_color(button, lv_color_lighten(color_primary, 100), LV_PART_MAIN);
  lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t) (index+1));
  BattIconLabel = lv_label_create(button);
  lv_label_set_text(BattIconLabel, LV_SYMBOL_DOWN);
  lv_obj_center(BattIconLabel);
  lv_obj_set_style_text_font(BattIconLabel, &lv_font_montserrat_16, LV_PART_MAIN);

    -- create a button Stop
  button = lv_btn_create(menuBox);
  lv_obj_set_size(button, 28, 28);
  lv_obj_align(button, LV_ALIGN_TOP_RIGHT, -50, 20);
  lv_obj_set_style_radius(button, 5, LV_PART_MAIN);
  lv_obj_set_style_bg_color(button, lv_color_lighten(color_primary, 100), LV_PART_MAIN);
  lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t) (index+2));
  BattIconLabel = lv_label_create(button);
  lv_label_set_text(BattIconLabel, LV_SYMBOL_PAUSE);
  lv_obj_center(BattIconLabel);
  lv_obj_set_style_text_font(BattIconLabel, &lv_font_montserrat_16, LV_PART_MAIN);

     -- create a button UP
  button = lv_btn_create(menuBox);
  lv_obj_set_size(button, 28, 28);
  lv_obj_align(button, LV_ALIGN_TOP_RIGHT, 0, 20);
  lv_obj_set_style_radius(button, 5, LV_PART_MAIN);
  lv_obj_set_style_bg_color(button, lv_color_lighten(color_primary, 100), LV_PART_MAIN);
  lv_obj_add_event_cb(button, button_clicked_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t) (index+3));
  BattIconLabel = lv_label_create(button);
  lv_label_set_text(BattIconLabel, LV_SYMBOL_UP);
  lv_obj_center(BattIconLabel);
  lv_obj_set_style_text_font(BattIconLabel, &lv_font_montserrat_16, LV_PART_MAIN);
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
  
  // Add another tab
  menuLabel = lv_label_create(tab);
  lv_label_set_text(menuLabel, "Rollo");

  createRollo(tab, "Strasse", 10);
  createRollo(tab, "Gross",   20);
  createRollo(tab, "Tuer",    30);
  createRollo(tab, "Fest",    40);
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
