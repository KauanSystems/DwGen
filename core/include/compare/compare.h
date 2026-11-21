#pragma once

#include <string>
#include <vector>
#include <filesystem>

namespace Core {

	std::vector<std::string> Compare(const std::filesystem::path& file_patch, const int& text);

} // Namespace Core.
