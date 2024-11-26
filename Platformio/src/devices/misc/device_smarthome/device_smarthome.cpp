#include "applicationInternal/commandHandler.h"
#include "device_smarthome.h"
uint16_t SMARTHOME_MQTT_TV                ;
uint16_t SMARTHOME_MQTT_LICHT_LINKS       ;
uint16_t SMARTHOME_MQTT_LICHT_MITTE       ;
uint16_t SMARTHOME_MQTT_LICHT_RECHTS      ;
uint16_t SMARTHOME_MQTT_LICHT_COUTCH      ;
uint16_t SMARTHOME_MQTT_LICHT_ESSEN       ;
uint16_t SMARTHOME_MQTT_FHEM              ;

uint16_t SMARTHOME_OMOTE_VU_ENABLE        ;
uint16_t SMARTHOME_OMOTE_VU_POWER         ;

void register_device_smarthome() {
  #if (ENABLE_WIFI_AND_MQTT == 1)
  register_command(&SMARTHOME_MQTT_TV                   , makeCommandData(MQTT, {"homegear/1/set/10/7/STATE"})); // payload must be set when calling commandHandler
  register_command(&SMARTHOME_MQTT_LICHT_LINKS          , makeCommandData(MQTT, {"homegear/1/set/4/15/STATE"})); // payload must be set when calling commandHandler
  register_command(&SMARTHOME_MQTT_LICHT_MITTE          , makeCommandData(MQTT, {"homegear/1/set/4/17/STATE"})); // payload must be set when calling commandHandler
  register_command(&SMARTHOME_MQTT_LICHT_RECHTS         , makeCommandData(MQTT, {"homegear/1/set/4/18/STATE"})); // payload must be set when calling commandHandler
  register_command(&SMARTHOME_MQTT_LICHT_COUTCH         , makeCommandData(MQTT, {"homegear/1/set/4/16/STATE"})); // payload must be set when calling commandHandler
  register_command(&SMARTHOME_MQTT_LICHT_ESSEN          , makeCommandData(MQTT, {"homegear/1/set/4/19/STATE"})); // payload must be set when calling commandHandler
  register_command(&SMARTHOME_MQTT_FHEM                 , makeCommandData(MQTT, {"/Service/fhem/cmnd"}));        // payload must be set when calling commandHandler
  
  register_command(&SMARTHOME_OMOTE_VU_ENABLE           , makeCommandData(MQTT, {"OMOTE/VU/Enabel"}));           // payload must be set when calling commandHandler
  register_command(&SMARTHOME_OMOTE_VU_POWER            , makeCommandData(MQTT, {"OMOTE/VU/Power"}));            // payload must be set when calling commandHandler
  #endif
}
