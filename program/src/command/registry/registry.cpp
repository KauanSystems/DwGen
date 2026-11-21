#include <registry.h>

#include <algorithm>
#include <iostream>
#include <vector>

namespace Program {

namespace {

	std::vector<Command>& GetRegistry() {
	    static std::vector<Command> registry;
	    return registry;
	}

	void Usage() {
		std::cout
		<< "\nUsage: "
		<< " <command>\n\n"
		<< "For Command Help Table Use: "
		<< " --help or -h.\n\n";
	} // Usage();

	} // namespace

	void RegisterCommand(Command cmd) {
	    if (!cmd.names.empty()) {
		GetRegistry().push_back(std::move(cmd));
	    }
	}

	const std::vector<Command>& GetCommands() {
	    return GetRegistry();
	}

	int Dispatch(int argc, const char* const argv[]) {
	    if (argc < 2) {
		Usage();
		return 1;
	    }

	    const std::string_view target{argv[1]};
	    const Args remaining_args{argv + 2, static_cast<size_t>(argc - 2)};
	    const auto& commands = GetRegistry();

	    const auto it = std::ranges::find_if(commands, [target](const Command& cmd) {
		return std::ranges::find(cmd.names, target) != cmd.names.end();
	    });

	    if (it != commands.end()) {
		return it->handler(remaining_args);
	    }

	    Usage();
	    return 1;
	}

} // namespace Program.
