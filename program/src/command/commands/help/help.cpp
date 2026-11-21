#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include <registry.h>
#include <version.hpp>

namespace {

	int Help(Program::Args) {
	    std::cout << "\n\n"
		<< PROJECT_NAME << " - "
		<<  "v" << PROJECT_VERSION << " - "
		<< "Copyright: "<< PROJECT_AUTHOR << " "
		<< DEV_YEAR << " - " << CURRENT_YEAR << " ©.\n\n";

	    auto commands = Program::GetCommands();
	    std::ranges::sort(commands, {}, [](const Program::Command& c) { return c.names.front(); });

	    for (const auto& cmd : commands) {
		std::string aliases;
		for (size_t i = 0; i < cmd.names.size(); ++i) {
		    aliases += cmd.names[i];
		    if (i + 1 < cmd.names.size()) {
		        aliases += ", ";
		    } // if.
		} // for.
		std::cout << std::left << std::setw(30) << aliases << std::setw(30) << cmd.description << cmd.type << '\n';
	    } std::cout << "\n\n";
	    
	    return 0;
	} // Help();

const Program::AutoRegister kRegHelp{
    {"--help", "-h", "help"}, &Help,
    "Show Help Table",
    "Flag"
};

} // namespace.
