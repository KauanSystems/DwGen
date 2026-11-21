# include <iostream>
# include <string_view>
# include <algorithm>
# include <array>
# include <vector>
# include <string>
#include <filesystem>

#include <verify.h>
#include <program.h>

namespace Core {

	bool VerifyFile(const std::filesystem::path& export_dir, const std::filesystem::path& file_pat) {
		bool file_exists =
			std::filesystem::exists(FILE_NAME) ||
			(!export_dir.empty() && std::filesystem::exists(file_pat));

		if (!file_exists) {
			return true;
		}

		std::string response;

		std::cout
			<< "\n[Warning]"
			<< "\nThe File "
			<< FILE_NAME
			<< " already exists. Do you want to delete it? (Y/n): ";

		std::getline(std::cin, response);

		if (response.empty()) {
			response = "y";
		}

		std::transform(
			response.begin(),
			response.end(),
			response.begin(),
			[](unsigned char c) {
			    return static_cast<char>(std::tolower(c));
			}
		);

		if (response == "y" || response == "yes") {
			std::cout
			    << "\n[Last Chance]\n"
			    << "This action is IRREVERSIBLE."
			    << " Do you wish to continue? (Y/n): ";

			std::getline(std::cin, response);

			if (response.empty()) {
			    response = "y";
			}

			std::transform(
			    response.begin(),
			    response.end(),
			    response.begin(),
			    [](unsigned char c) {
				return static_cast<char>(std::tolower(c));
			    }
			);

			if (response == "y" || response == "yes") {
			    if (std::filesystem::exists(FILE_NAME)) {
				std::filesystem::remove(FILE_NAME);
			    }

			    if (!export_dir.empty() && std::filesystem::exists(file_pat)) {
				std::filesystem::remove(file_pat);
			    }
			    return true;
			}
			else {
			    std::cout << "\nOperation cancelled.\n\n";
			    return false;
			}
		}
		else {
			std::cout << "\nOperation cancelled.\n\n";
			return false;
		}
	} // VerifyFile().
	
} // namespace Core.
