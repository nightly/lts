#pragma once

#include <string>
#include <ostream>
#include <filesystem>

#include "lts/lts.h"
#include "lts/state.h"
#include "lts/writers.h"
#include "lts/internal/directory.h"

namespace nightly {

	/**
	 * @brief Exports a given LTS to the provided path, which can be visualised via GraphViz. Uses ofstream overloads.
	 * @param lts: labelled transition system in question to write to file
	 * @param path: export filepath, missing directories will be created. Filepath should include file extension.
	 * @exception Propagates std::ofstream::failure
	 */
	template <typename KeyT = std::string, typename TransitionT = std::string, typename HashF = std::hash<KeyT>>
	void ExportToFile(const LTS<KeyT, TransitionT, HashF>& lts, const std::filesystem::path& path) {
		std::ofstream stream;
		stream.exceptions(std::ofstream::badbit);
		CreateDirectoryForPath(path);
		try {
			stream.open(path, std::ios::out | std::ios::trunc);
			stream << lts;
		} catch (const std::ofstream::failure& e) {
			throw;
		}
	}

}