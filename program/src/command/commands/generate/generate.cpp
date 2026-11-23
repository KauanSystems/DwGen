#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <filesystem>
#include <fstream>
#include <charconv>

#include <registry.h>
#include <generator.h>
#include <compare.h>
#include <export.h>
#include <verify.h>
#include <program.h>

#include <wordlist.hpp>

namespace {

	static std::filesystem::path Materialize_Wordlist(std::string_view content) {
	    std::error_code ec;
	    auto temp_path = std::filesystem::temp_directory_path(ec) / "embedded_wordlist.txt";
	    
	    if (ec) {
		temp_path = std::filesystem::path("/tmp/embedded_wordlist.txt");
	    }
	    
	    std::ofstream out(temp_path, std::ios::binary | std::ios::trunc);
	    out.write(content.data(), static_cast<std::streamsize>(content.size()));
	    out.close();
	    
	    return temp_path;
	} // Materialize_Wordlist();

	int Generate(Program::Args args) {
	    std::filesystem::path file = Materialize_Wordlist(EMBEDDED_WORDLIST);
	    std::filesystem::path file_m;
	    bool export_file = false;
	    bool word_mode = false;
	    int max_iter = 5;

	    for (std::size_t i = 0; i < args.size(); ++i) {
		std::string_view arg = args[i];

		if (arg == "-e") {
			export_file = true;
			continue;
		} // if.

		if (arg == "-w") {
			word_mode = true;
			if (i + 1 >= args.size()) {
				std::cerr
					<< "\n[Error] -w requires a file path.\n\n";
				return 1;
			} // if.
			std::string_view next_arg = args[i + 1];
			if (next_arg.empty() || next_arg.front() == '-') {
				std::cerr
					<< "\n[Error] Invalid file path after -w: " << next_arg << "\n\n";
				return 1;
			} // if.
			file = next_arg;
			++i;
			continue;
		} // if.

		int parsed = 0;
		auto [ptr, ec] = std::from_chars(arg.data(), arg.data() + arg.size(), parsed);
		if (ec == std::errc{} && ptr == arg.data() + arg.size()) {
			if (i != 0) {
				std::cerr
					<< "\n[Error] The number of iterations must be the first argument.\n\n";
				return 1;
			}
			if (parsed < 0) {
				std::cerr
					<< "\n[Error] The number of iterations cannot be less than 0.\n\n";
				return 1;
			}
			max_iter = parsed;
		} // if.
	    } // for
	    
	    if (max_iter <= 0) {
	    	std::cerr
	    		<< "\n[Error] Number of iterations must be greater than 0.\n\n";
	    	return 1;
	    }
	    
	    if (max_iter <= 4) {
	    	std::cerr
	    		<< "\n[Error] The number of iterations must not be less than 5.\n\n";
	    	return 1;
	    }
	    
	    if (max_iter > 10) {
	    	Core::VerifyWordCount(max_iter);
	    }
	    
	    if (word_mode) {
		std::filesystem::path target_file(file);
		std::ifstream stream(target_file);
		std::string line;
		int line_count = 0;
		
		if (file.empty() || !std::filesystem::exists(target_file)) {
		    std::cout
		    	    << "The File not exists.\n";
		    return 0;
		}
		
		if (!stream.is_open()) {
		    std::cerr
		    	    << "\n[Error] Unable to open the file.\n\n";
		    return 0;
		}

		while (std::getline(stream, line)) {
		    ++line_count;
		}

		if (line_count != 7776) {
		    std::cerr
		    	    << "\n[Error] The file must contain exactly 7776 lines.\n\n";
		    return 0;
		}
	    } // if.
	
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
