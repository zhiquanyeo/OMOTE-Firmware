#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_kinvioBN550.h"

uint16_t BN550_INPUT_1;
uint16_t BN550_INPUT_2;
uint16_t BN550_INPUT_3;
uint16_t BN550_INPUT_4;
uint16_t BN550_INPUT_5;
uint16_t BN550_NEXT_INPUT;
uint16_t BN550_PREV_INPUT;

void register_device_kinvioBN550() {
    register_command(&BN550_INPUT_1     , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x40BF609F"}));
    register_command(&BN550_INPUT_2     , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x40BF50AF"}));
    register_command(&BN550_INPUT_3     , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x40BF708F"}));
    register_command(&BN550_INPUT_4     , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x40BF906F"}));
    register_command(&BN550_INPUT_5     , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x40BFB04F"}));
    register_command(&BN550_NEXT_INPUT  , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x40BF00FF"}));
    register_command(&BN550_PREV_INPUT  , makeCommandData(IR, {std::to_string(IR_PROTOCOL_NEC), "0x40BF20DF"}));
}