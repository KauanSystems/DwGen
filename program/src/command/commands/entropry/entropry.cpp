#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <filesystem>
#include <fstream>

#include <registry.h>
#include <version.hpp>

namespace {

	struct Tier {
	    int words;
	    std::string level;
	    std::string guidance;
	};

	void CheckEntropy(int wordlistSize) {
	    // Entropy per word: log2(wordlistSize) (~12.925 bits for 7776 words)
	    const double bitsPerWord = std::log2(static_cast<double>(wordlistSize));

	    const std::vector<Tier> tiers = {
		{5, "Minimum acceptable", "For common accounts with brute-force rate limits."},
		{6, "Recommended standard", "Good balance for important accounts and password managers."},
		{7, "High security", "Ideal for master passwords and full-disk encryption."},
		{8, "Practical maximum", "Extreme security; more words hurt usability with little gain."}
	    };

	    std::cout << PROJECT_NAME << " - Entropy Guide (Wordlist size: " << wordlistSize
		      << ", ~" << std::fixed << std::setprecision(2) << bitsPerWord
		      << " bits/word):\n\n";

	    std::cout << std::left
		      << std::setw(12) << "Words"
		      << std::setw(20) << "Entropy (bits)"
		      << std::setw(28) << "Security Level"
		      << "Guidance\n";
	    std::cout << std::string(120, '-') << "\n";

	    for (const auto& tier : tiers) {
		double totalEntropy = tier.words * bitsPerWord;
		std::cout << std::left
		          << std::setw(12) << tier.words
		          << std::setw(20) << (std::to_string(static_cast<int>(std::round(totalEntropy))) + " bits")
		          << std::setw(28) << tier.level
		          << tier.guidance << "\n";
	    }
	} // CheckEntropy();
	
	int DoEntropy(Program::Args args) {
		std::filesystem::path file;
		std::size_t line_count = 0;
		std::string line;
		
		for (std::size_t i = 0; i < args.size(); ++i) {
			std::string_view arg = args[i];

			if (arg.empty()) {
				std::cerr
					<< "\n[Error] Invalid file path.\n\n";
				return 1;
			}

			file = arg;
		} // for.

		if (file.empty()) {
			std::cerr
				<< "\n[Error] A file path is required.\n\n";
			return 1;
		}

		std::error_code ec;
		if (std::filesystem::is_directory(file, ec)) {
			std::cerr
				<< "\n[Error] Path is a directory, not a file: " << file << "\n\n";
			return 1;
		}

		std::ifstream in(file);
		if (!in.is_open()) {
			std::cerr
				<< "\n[Error] Could not open file: " << file << "\n\n";
			return 1;
		}

		while (std::getline(in, line)) {
			++line_count;
		}
		
		std::cout << "\n";
		CheckEntropy(line_count);
		std::cout << "\n\n";
		
		return 0;
	} // DoEntropy();

const Program::AutoRegister kRegEntropy{
    {"--entropy", "-en", "entropy"}, &DoEntropy,
    "Show Entropy Table Check.",
    "Flag"
};

} // namespace.
