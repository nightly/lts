#pragma once

#include <string>
#include <ostream>
#include <filesystem>

#include "lts/lts.h"
#include "lts/state.h"
#include "lts/writers/ofstream.h"
#include "lts/internal/directory.h"
#include "lts/writers/styling.h"

namespace nightly {

	/**
	 * @brief Exports a given LTS to the provided path, which can be visualised via GraphViz. Uses ofstream overloads.
	 * @param lts: labelled transition system in question to write to file
	 * @param path: export filepath, missing directories will be created. Filepath should include file extension.
	 * @param font: allows specifying a custom font for output
	 * @param font_check: uses a distinct font to check whether the custom specified font has been applied
	 * @exception Propagates std::ofstream::failure
	 */
	template <typename KeyT = std::string, typename TransitionT = std::string, typename HashF = std::hash<KeyT>>
	void ExportToFile(const LTS<KeyT, TransitionT, HashF>& lts, const std::filesystem::path& path,
		             const Styling& style = Styling(), bool write_x_label = false) {
		std::ofstream stream;
		stream.exceptions(std::ofstream::badbit);
		CreateDirectoryForPath(path);
		try {
			stream.open(path, std::ios::out | std::ios::trunc);
			PrintGraphVizLTS(stream, lts, style, write_x_label);
		} catch (const std::ofstream::failure& e) {
			throw;
		}
	}

}