#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include <registry.h>
#include <version.hpp>

namespace {

	int Logo(Program::Args) {
	    std::cout << "\n\n"
		<< PROJECT_NAME << " - "
		<<  "v" << PROJECT_VERSION << " - "
		<< "Copyright: "<< PROJECT_AUTHOR << " "
		<< DEV_YEAR << " - " << CURRENT_YEAR << " ©.\n\n";

	    return 0;
	} // Logo();

const Program::AutoRegister kRegLogo{
    {"--logo", "-l", "logo"}, &Logo,
    "Show Program Logo.",
    "Flag"
};

} // namespace.
