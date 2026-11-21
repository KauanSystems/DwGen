#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include <registry.h>
#include <version.hpp>

namespace {

	int Creator(Program::Args) {
	    std::cout << "\n\n"
		<< "Copyright: "<< PROJECT_AUTHOR << " "
		<< DEV_YEAR << " - " << CURRENT_YEAR << " ©.\n\n"
		<< AUTHOR_CONTACT << "\n\n";

	    return 0;
	} // Creator();

const Program::AutoRegister kRegCreator{
    {"--creator", "-c", "creator"}, &Creator,
    "Show Creator Contact.",
    "Flag"
};

} // namespace.
