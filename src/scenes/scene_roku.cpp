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
#include "devices/mediaPlayer/device_roku/device_rokuMQTT.h"
#include "applicationInternal/commandHandler.h"

// GUIs
#include "devices/mediaPlayer/device_roku/gui_roku.h"

uint16_t SCENE_ROKU         ; //"Scene_roku"
uint16_t SCENE_ROKU_FORCE   ; //"Scene_roku_force"

std::map<char, repeatModes> key_repeatModes_roku;
std::map<char, uint16_t> key_commands_short_roku;
std::map<char, uint16_t> key_commands_long_roku;

void scene_setKeys_roku() {
  key_repeatModes_roku = {
    {KEY_REWI, SHORT_REPEATED},
    {KEY_FORW, SHORT_REPEATED},
    {KEY_PLAY, SHORT},
    {KEY_STOP, SHORT},
    {KEY_LEFT, SHORT_REPEATED},
    {KEY_RIGHT, SHORT_REPEATED},
    {KEY_UP, SHORT_REPEATED},
    {KEY_DOWN, SHORT_REPEATED},
    {KEY_OK, SHORT},
    {KEY_CONF, SHORT},
    {KEY_INFO, SHORT},
    {KEY_BACK, SHORT}









  };

  key_commands_short_roku = {
    {KEY_STOP, ROKU_REPLAY},
    {KEY_PLAY, ROKU_PLAY},
    {KEY_REWI, ROKU_RWD},
    {KEY_FORW, ROKU_FF},

    {KEY_CONF, ROKU_HOME},
    {KEY_BACK, ROKU_BACK},
    {KEY_INFO, ROKU_STAR},

    {KEY_LEFT, ROKU_LEFT},
    {KEY_RIGHT, ROKU_RIGHT},
    {KEY_UP, ROKU_UP},
    {KEY_DOWN, ROKU_DOWN},
    {KEY_OK, ROKU_OK}
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
t_gui_list scene_roku_gui_list = {tabName_roku};

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
        & scene_roku_gui_list,
        SCENE_ROKU);
}
