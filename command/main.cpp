#include <iostream>
#include <memory>

#include "Commands.hpp"
#include "Devices.hpp"
#include "RemoteControl.hpp"

int main() {
    RemoteControl remoteControl;

    Light livingRoomLight("リビングルーム");
    Light kitchenLight("キッチン");
    CeilingFan ceilingFan("リビングルーム");
    GarageDoor garageDoor("ガレージ");
    Stereo stereo("リビングルーム");

    auto livingRoomLightOn = std::make_shared<LightOnCommand>(livingRoomLight);
    auto livingRoomLightOff = std::make_shared<LightOffCommand>(livingRoomLight);
    auto kitchenLightOn = std::make_shared<LightOnCommand>(kitchenLight);
    auto kitchenLightOff = std::make_shared<LightOffCommand>(kitchenLight);

    auto ceilingFanOn = std::make_shared<CeilingFanOnCommand>(ceilingFan);
    auto ceilingFanOff = std::make_shared<CeilingFanOffCommand>(ceilingFan);

    auto garageDoorUp = std::make_shared<GarageDoorUpCommand>(garageDoor);
    auto garageDoorDown = std::make_shared<GarageDoorDownCommand>(garageDoor);
    (void)garageDoorUp;
    (void)garageDoorDown;

    auto stereoOnWithCD = std::make_shared<StereoOnWithCDCommand>(stereo);
    auto stereoOff = std::make_shared<StereoOffCommand>(stereo);

    remoteControl.setCommand(0, livingRoomLightOn, livingRoomLightOff);
    remoteControl.setCommand(1, kitchenLightOn, kitchenLightOff);
    remoteControl.setCommand(2, ceilingFanOn, ceilingFanOff);
    remoteControl.setCommand(3, stereoOnWithCD, stereoOff);

    std::cout << remoteControl << std::endl;

    remoteControl.onButtonWasPushed(0);
    remoteControl.offButtonWasPushed(0);
    remoteControl.onButtonWasPushed(1);
    remoteControl.offButtonWasPushed(1);
    remoteControl.onButtonWasPushed(2);
    remoteControl.offButtonWasPushed(2);
    remoteControl.onButtonWasPushed(3);
    remoteControl.offButtonWasPushed(3);

    return 0;
}
