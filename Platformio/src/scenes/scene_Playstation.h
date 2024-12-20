#pragma once

#include <string>
#include <stdint.h>

extern uint16_t SCENE_PLAYSTATION;
// FORCE sends the start sequence again even if scene is already active
extern uint16_t SCENE_PLAYSTATION_FORCE;

extern std::string scene_name_Playstation;
void register_scene_SCENE_Playstation_commands(void);
void register_scene_Playstation(void);
