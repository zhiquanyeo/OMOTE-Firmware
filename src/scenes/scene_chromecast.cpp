#include <map>
#include "scenes/scene_chromecast.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
#include "devices/TV/device_samsungTV/device_samsungTV.h"
#include "devices/misc/device_kinvioBN550/device_kinvioBN550.h"
#include "devices/TV/device_tvMQTT/device_tvMQTT.h"
#include "applicationInternal/commandHandler.h"

uint16_t SCENE_CHROMECAST      ; //"Scene_chromecast"
uint16_t SCENE_CHROMECAST_FORCE; //"Scene_chromecast_force"

std::map<char, repeatModes> key_repeatModes_chromecast;
std::map<char, uint16_t> key_commands_short_chromecast;
std::map<char, uint16_t> key_commands_long_chromecast;

void scene_setKeys_chromecast() {
  key_repeatModes_chromecast = {










  };

  key_commands_short_chromecast = {










  };

  key_commands_long_chromecast = {


  };

}

void scene_start_sequence_chromecast(void) {
  executeCommand(TV_MQTT_POWER_ON);
  delay(500);
  executeCommand(TV_MQTT_INPUT_HDMI_3);
}

void scene_end_sequence_chromecast(void) {

}

std::string scene_name_chromecast = "Chromecast";

void register_scene_chromecast(void) {
  register_command(&SCENE_CHROMECAST,       makeCommandData(SCENE, {scene_name_chromecast}));
  register_command(&SCENE_CHROMECAST_FORCE, makeCommandData(SCENE, {scene_name_chromecast, "FORCE"}));

  register_scene(
    scene_name_chromecast,
    & scene_setKeys_chromecast,
    & scene_start_sequence_chromecast,
    & scene_end_sequence_chromecast,
    & key_repeatModes_chromecast,
    & key_commands_short_chromecast,
    & key_commands_long_chromecast,
    NULL,
    SCENE_CHROMECAST);
}
