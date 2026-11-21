#include <iostream>

#include <registry.h>

namespace {

	int System(Program::Args) {
		#if defined(__linux__)
		    std::cout << "\n[Operating System]: Linux Detected - [Using getrandom].\n\n";
		#elif defined(_WIN32) || defined(_WIN64)
		    std::cout << "\n[Operating System]: Windows Detected - [Using BCryptGenRandom].\n\n";
		#else
		    std::cout << "\n[Operating System]: Not Detected - Unknown.\n\n";
		#endif

	    return 0;
	} // System();

const Program::AutoRegister kRegSystem{
    {"--system", "-s", "system"}, &System,
    "Show Program Logo.",
    "Flag"
};

} // namespace.
