#include "applicationInternal/commandHandler.h"
#include "device_rokuMQTT.h"

uint16_t ROKU_UP;
uint16_t ROKU_DOWN;
uint16_t ROKU_LEFT;
uint16_t ROKU_RIGHT;
uint16_t ROKU_OK;

uint16_t ROKU_PLAY;
uint16_t ROKU_REPLAY;
uint16_t ROKU_RWD;
uint16_t ROKU_FF;

uint16_t ROKU_BACK;
uint16_t ROKU_HOME;
uint16_t ROKU_STAR;

uint16_t ROKU_APP; // Need to provide the ID or string

void register_device_rokuMQTT() {
    #if (ENABLE_WIFI_AND_MQTT == 1)
    register_command(&ROKU_UP,      makeCommandData(MQTT, {"OMOTE/roku/navigation", "UP"}));
    register_command(&ROKU_DOWN,    makeCommandData(MQTT, {"OMOTE/roku/navigation", "DOWN"}));
    register_command(&ROKU_LEFT,    makeCommandData(MQTT, {"OMOTE/roku/navigation", "LEFT"}));
    register_command(&ROKU_RIGHT,   makeCommandData(MQTT, {"OMOTE/roku/navigation", "RIGHT"}));
    register_command(&ROKU_OK,      makeCommandData(MQTT, {"OMOTE/roku/navigation", "OK"}));

    register_command(&ROKU_PLAY,    makeCommandData(MQTT, {"OMOTE/roku/media", "PLAY"}));
    register_command(&ROKU_REPLAY,  makeCommandData(MQTT, {"OMOTE/roku/media", "REPLAY"}));
    register_command(&ROKU_RWD,     makeCommandData(MQTT, {"OMOTE/roku/media", "REWIND"}));
    register_command(&ROKU_FF,      makeCommandData(MQTT, {"OMOTE/roku/media", "FFWD"}));

    register_command(&ROKU_BACK,    makeCommandData(MQTT, {"OMOTE/roku/system", "BACK"}));
    register_command(&ROKU_HOME,    makeCommandData(MQTT, {"OMOTE/roku/system", "HOME"}));
    register_command(&ROKU_STAR,    makeCommandData(MQTT, {"OMOTE/roku/system", "STAR"}));

    register_command(&ROKU_APP,     makeCommandData(MQTT, {"OMOTE/roku/app"}));
    #endif
}
