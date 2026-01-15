#include "applicationInternal/commandHandler.h"
#include "device_hdmiSwitchMQTT.h"

uint16_t HDMI_SWITCH_INPUT_HDMI;
uint16_t HDMI_SWITCH_NEXT_INPUT;
uint16_t HDMI_SWITCH_PREV_INPUT;

uint16_t HDMI_SWITCH_INPUT_HDMI_1;
uint16_t HDMI_SWITCH_INPUT_HDMI_2;
uint16_t HDMI_SWITCH_INPUT_HDMI_3;
uint16_t HDMI_SWITCH_INPUT_HDMI_4;
uint16_t HDMI_SWITCH_INPUT_HDMI_5;

void register_device_hdmiSwitchMQTT() {
    #if (ENABLE_WIFI_AND_MQTT == 1)
    register_command(&HDMI_SWITCH_INPUT_HDMI, makeCommandData(MQTT, {"OMOTE/livingroom-hdmi-switch/input"}));
    register_command(&HDMI_SWITCH_NEXT_INPUT, makeCommandData(MQTT, {"OMOTE/livingroom-hdmi-switch/input", "NEXT"}));
    register_command(&HDMI_SWITCH_PREV_INPUT, makeCommandData(MQTT, {"OMOTE/livingroom-hdmi-switch/input", "PREV"}));

    register_command(&HDMI_SWITCH_INPUT_HDMI_1, makeCommandData(MQTT, {"OMOTE/livingroom-hdmi-switch/input", "1"}));
    register_command(&HDMI_SWITCH_INPUT_HDMI_2, makeCommandData(MQTT, {"OMOTE/livingroom-hdmi-switch/input", "2"}));
    register_command(&HDMI_SWITCH_INPUT_HDMI_3, makeCommandData(MQTT, {"OMOTE/livingroom-hdmi-switch/input", "3"}));
    register_command(&HDMI_SWITCH_INPUT_HDMI_4, makeCommandData(MQTT, {"OMOTE/livingroom-hdmi-switch/input", "4"}));
    register_command(&HDMI_SWITCH_INPUT_HDMI_5, makeCommandData(MQTT, {"OMOTE/livingroom-hdmi-switch/input", "5"}));
    #endif
}