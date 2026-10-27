#pragma once

#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <typeinfo>
#include <utility>

#if defined(__has_include)
#  if __has_include(<cxxabi.h>)
#    include <cxxabi.h>
#    define HAS_CXXABI 1
#  endif
#endif

#include "Command.hpp"

inline std::string classNameOf(const Command& cmd) {
    const char* raw = typeid(cmd).name();
#ifdef HAS_CXXABI
    int status = 0;
    std::unique_ptr<char, void (*)(void*)> demangled(
        abi::__cxa_demangle(raw, nullptr, nullptr, &status), std::free);
    return (status == 0 && demangled) ? demangled.get() : raw;
#else
    return raw;
#endif
}

class RemoteControl {
public:
    static constexpr std::size_t kSlotCount = 7;

    RemoteControl() {
        auto noCommand = std::make_shared<NoCommand>();
        onCommands_.fill(noCommand);
        offCommands_.fill(noCommand);
    }

    void setCommand(std::size_t slot,
                    std::shared_ptr<Command> onCommand,
                    std::shared_ptr<Command> offCommand) {
        onCommands_.at(slot) = std::move(onCommand);
        offCommands_.at(slot) = std::move(offCommand);
    }

    void onButtonWasPushed(std::size_t slot) { onCommands_.at(slot)->execute(); }
    void offButtonWasPushed(std::size_t slot) { offCommands_.at(slot)->execute(); }

    std::string toString() const {
        std::ostringstream out;
        out << "\n------ リモコン -------\n";
        for (std::size_t i = 0; i < kSlotCount; ++i) {
            out << " [スロット" << i << "] " << std::left << std::setw(24)
                << classNameOf(*onCommands_[i]) << classNameOf(*offCommands_[i]) << "\n";
        }
        return out.str();
    }

private:
    std::array<std::shared_ptr<Command>, kSlotCount> onCommands_;
    std::array<std::shared_ptr<Command>, kSlotCount> offCommands_;
};

inline std::ostream& operator<<(std::ostream& os, const RemoteControl& rc) {
    return os << rc.toString();
}
