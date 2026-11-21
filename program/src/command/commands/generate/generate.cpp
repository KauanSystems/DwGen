#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <filesystem>

#include <registry.h>
#include <generator.h>
#include <compare.h>
#include <export.h>
#include <verify.h>
#include <program.h>

namespace {

	int Generate(Program::Args args) {
	    std::filesystem::path file = WORD;
	    std::filesystem::path file_m;
	    bool export_file = false;
	    int max_iter = 5;
	    
	    for (std::string_view arg : args) {
		if (arg == "-e") { export_file = true; }
	    } // for.
	    
	    std::filesystem::path dir(file_m);

	    std::filesystem::path file_path =
		dir.empty()
			? std::filesystem::path(FILE_NAME)
			: dir / FILE_NAME;

		if (export_file) {
			if (!Core::VerifyFile(file_m, file_path)) {
				return 0;
			} // if.
		} // if.

	    std::cout << "\n\n";
		for (int i = 1; i <= max_iter; ++i) {
			auto num = Core::Generate_data();
			auto results = Core::Compare(file, num);

			for (const std::string& res : results) {
			    std::cout
				<< num
				<< " -> "
				<< res
				<< "\n";
				
			    if (export_file) {
				    for (const std::string& res : results) {
					Core::Export(res, file_m.string());
				    } // for.
			    } // if.
			} // for.
		} std::cout << "\n\n";

	    return 0;
	} // Generate();

const Program::AutoRegister kRegGen{
    {"-g", "generate"}, &Generate,
    "Generate Dice Data.",
    "Command"
};

} // namespace.
