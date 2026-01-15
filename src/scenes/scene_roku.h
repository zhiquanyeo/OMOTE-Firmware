#pragma once

#include <string>
#include <stdint.h>

extern uint16_t SCENE_ROKU;
extern uint16_t SCENE_ROKU_FORCE;

extern std::string scene_name_roku;
void register_scene_roku_commands(void);
void register_scene_roku(void);