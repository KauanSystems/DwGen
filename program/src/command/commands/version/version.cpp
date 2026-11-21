#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include <registry.h>
#include <version.hpp>

namespace {

	int Version(Program::Args) {
	    std::cout << "\n\n"
		<< PROJECT_NAME << " - "
		<<  "v" << PROJECT_VERSION << " - "
		<< DEV_YEAR << " - " << CURRENT_YEAR << " ©.\n\n";

	    return 0;
	} // Version();

const Program::AutoRegister kRegVersion{
    {"--version", "-v", "version"}, &Version,
    "Show Program Logo.",
    "Flag"
};

} // namespace.
