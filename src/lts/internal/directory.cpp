#include "directory.h"

#include <filesystem>
#include <ostream>

namespace nightly {

	void CreateDirectoryForPath(const std::filesystem::path& path) {
		if (!std::filesystem::is_directory(path.parent_path()) && path.has_parent_path()) {
			std::filesystem::create_directories(path.parent_path());
		}
	}
}