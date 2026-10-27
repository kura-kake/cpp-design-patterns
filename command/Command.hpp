#pragma once

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class NoCommand : public Command {
public:
    void execute() override {}
};
