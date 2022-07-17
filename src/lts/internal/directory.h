#pragma once

#include <filesystem>
#include <ostream>

namespace nightly {

	void CreateDirectoryForPath(const std::filesystem::path& path);

}