#pragma once

#include <initializer_list>
#include <span>
#include <string_view>
#include <vector>

namespace Program {

using Args = std::span<const char* const>;
using CommandHandler = int (*)(Args);

struct Command {
    std::vector<std::string_view> names;
    CommandHandler handler;
    std::string_view description;
    std::string_view type;
};

void RegisterCommand(Command cmd);
const std::vector<Command>& GetCommands();
int Dispatch(int argc, const char* const argv[]);

struct AutoRegister {
    AutoRegister(std::initializer_list<std::string_view> names,
                 CommandHandler handler,
                 std::string_view description,
                 std::string_view type = "General") {
        RegisterCommand({std::vector<std::string_view>(names), handler, description, type});
    }
};

} // namespace Program.
