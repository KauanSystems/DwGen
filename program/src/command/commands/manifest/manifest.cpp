#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include <registry.h>
#include <version.hpp>

#include <manifest.h>

namespace {

	int Manifest(Program::Args) {
	    std::cout << "\n\n"
		<< PROJECT_NAME << " - "
		<<  "v" << PROJECT_VERSION << " - "
		<< "Copyright: "<< PROJECT_AUTHOR << " "
		<< DEV_YEAR << " - " << CURRENT_YEAR << " ©.\n\n";
		
	    std::cout << kSecurityNotice << '\n'; 

	    return 0;
	} // Manifest();

const Program::AutoRegister kRegManifest{
    {"--manifest", "-m", "manifest"}, &Manifest,
    "Show Program Manifest.",
    "Flag"
};

} // namespace.
