#include "applicationInternal/commandHandler.h"
#include "device_tvMQTT.h"

uint16_t TV_MQTT_POWER      ;
uint16_t TV_MQTT_VOL        ;
uint16_t TV_MQTT_INPUT_HDMI ;

uint16_t TV_MQTT_POWER_ON        ;
uint16_t TV_MQTT_POWER_OFF       ;
uint16_t TV_MQTT_VOL_UP          ;
uint16_t TV_MQTT_VOL_DOWN        ;
uint16_t TV_MQTT_INPUT_HDMI_1    ;
uint16_t TV_MQTT_INPUT_HDMI_2    ;
uint16_t TV_MQTT_INPUT_HDMI_3    ;
uint16_t TV_MQTT_INPUT_HDMI_4    ;

void register_device_tvMQTT() {
    #if (ENABLE_WIFI_AND_MQTT == 1)
    register_command(&TV_MQTT_POWER,        makeCommandData(MQTT, {"OMOTE/livingroom-tv/power"}));
    register_command(&TV_MQTT_VOL,          makeCommandData(MQTT, {"OMOTE/livingroom-tv/volume"}));
    register_command(&TV_MQTT_INPUT_HDMI,   makeCommandData(MQTT, {"OMOTE/livingroom-tv/input"}));

    register_command(&TV_MQTT_POWER_ON,     makeCommandData(MQTT, {"OMOTE/livingroom-tv/power", "ON"}));
    register_command(&TV_MQTT_POWER_OFF,    makeCommandData(MQTT, {"OMOTE/livingroom-tv/power", "OFF"}));
    register_command(&TV_MQTT_VOL_UP,       makeCommandData(MQTT, {"OMOTE/livingroom-tv/volume", "UP"}));
    register_command(&TV_MQTT_VOL_DOWN,     makeCommandData(MQTT, {"OMOTE/livingroom-tv/volume", "DOWN"}));
    register_command(&TV_MQTT_INPUT_HDMI_1, makeCommandData(MQTT, {"OMOTE/livingroom-tv/input", "1"}));
    register_command(&TV_MQTT_INPUT_HDMI_2, makeCommandData(MQTT, {"OMOTE/livingroom-tv/input", "2"}));
    register_command(&TV_MQTT_INPUT_HDMI_3, makeCommandData(MQTT, {"OMOTE/livingroom-tv/input", "3"}));
    register_command(&TV_MQTT_INPUT_HDMI_4, makeCommandData(MQTT, {"OMOTE/livingroom-tv/input", "4"}));
    #endif
}