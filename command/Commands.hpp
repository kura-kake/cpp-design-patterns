#pragma once

#include "Command.hpp"
#include "Devices.hpp"

class LightOnCommand : public Command {
public:
    explicit LightOnCommand(Light& light) : light_(light) {}
    void execute() override { light_.on(); }

private:
    Light& light_;
};

class LightOffCommand : public Command {
public:
    explicit LightOffCommand(Light& light) : light_(light) {}
    void execute() override { light_.off(); }

private:
    Light& light_;
};

class CeilingFanOnCommand : public Command {
public:
    explicit CeilingFanOnCommand(CeilingFan& fan) : fan_(fan) {}
    void execute() override { fan_.high(); }

private:
    CeilingFan& fan_;
};

class CeilingFanOffCommand : public Command {
public:
    explicit CeilingFanOffCommand(CeilingFan& fan) : fan_(fan) {}
    void execute() override { fan_.off(); }

private:
    CeilingFan& fan_;
};

class GarageDoorUpCommand : public Command {
public:
    explicit GarageDoorUpCommand(GarageDoor& door) : door_(door) {}
    void execute() override { door_.up(); }

private:
    GarageDoor& door_;
};

class GarageDoorDownCommand : public Command {
public:
    explicit GarageDoorDownCommand(GarageDoor& door) : door_(door) {}
    void execute() override { door_.down(); }

private:
    GarageDoor& door_;
};

class StereoOnWithCDCommand : public Command {
public:
    explicit StereoOnWithCDCommand(Stereo& stereo) : stereo_(stereo) {}
    void execute() override {
        stereo_.on();
        stereo_.setCD();
        stereo_.setVolume(11);
    }

private:
    Stereo& stereo_;
};

class StereoOffCommand : public Command {
public:
    explicit StereoOffCommand(Stereo& stereo) : stereo_(stereo) {}
    void execute() override { stereo_.off(); }

private:
    Stereo& stereo_;
};
