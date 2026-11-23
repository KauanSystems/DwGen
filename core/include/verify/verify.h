# include <iostream>
# include <string_view>
# include <algorithm>
# include <array>
# include <vector>
# include <string>
#include <filesystem>

namespace Core {

	bool VerifyFile(const std::filesystem::path& export_dir, const std::filesystem::path& file_pat);
	bool VerifyWordCount(int wordCount);
	
} // namespace Core.
