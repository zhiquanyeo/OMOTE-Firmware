#include <map>
#include "scenes/scene_roku.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"

// Devices
#include "devices/TV/device_samsungTV/device_samsungTV.h"
#include "devices/TV/device_tvMQTT/device_tvMQTT.h"
#include "devices/misc/device_hdmiSwitchMQTT/device_hdmiSwitchMQTT.h"
#include "devices/misc/device_kinvioBN550/device_kinvioBN550.h"
#include "applicationInternal/commandHandler.h"

// GUIs

uint16_t SCENE_ROKU         ; //"Scene_roku"
uint16_t SCENE_ROKU_FORCE   ; //"Scene_roku_force"

std::map<char, repeatModes> key_repeatModes_roku;
std::map<char, uint16_t> key_commands_short_roku;
std::map<char, uint16_t> key_commands_long_roku;

void scene_setKeys_roku() {
  key_repeatModes_roku = {










  };

  key_commands_short_roku = {










  };

  key_commands_long_roku = {


  };

}

void scene_start_sequence_roku(void) {
    executeCommand(TV_MQTT_POWER_ON);
    delay(500);
    executeCommand(TV_MQTT_INPUT_HDMI_4);
    delay(500);
    executeCommand(HDMI_SWITCH_INPUT_HDMI_1);
}

void scene_end_sequence_roku(void) {

}

std::string scene_name_roku = "Roku";

void register_scene_roku(void) {
    register_command(&SCENE_ROKU,       makeCommandData(SCENE, {scene_name_roku}));
    register_command(&SCENE_ROKU_FORCE, makeCommandData(SCENE, {scene_name_roku, "FORCE"}));

    register_scene(
        scene_name_roku,
        & scene_setKeys_roku,
        & scene_start_sequence_roku,
        & scene_end_sequence_roku,
        & key_repeatModes_roku,
        & key_commands_short_roku,
        & key_commands_long_roku,
        NULL,
        SCENE_ROKU);
}