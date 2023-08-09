#pragma once

#include <vector>
#include <span>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

#include "lts/lts.h"
#include "lts/parsers/state.h"
#include "lts/parsers/transition.h"
#include "lts/internal/strings.h"

namespace nightly {

	/**
	 * @brief Parses a text file into LTS (see `data/` folder for examples)
	 * First line of the file sets the initial state. Following lines add a transition in the form of:
	 *      InitialState
	 *		StartState. Action. EndState.
	 * @param lts: the Labelled Transition System to parse into
	 * @param path: path to text file
	 * @param delimiter: the delimiter used when parsing transitions to separate arguments
	 * @exception Propagates std::ifstream failure
	 */
	template <typename StateT, typename TransitionT, typename HashF>
	void ReadFromFile(LTS<StateT, TransitionT, HashF>& lts, const std::filesystem::path& filepath, const char delimiter = '.') {
		std::string line;
		bool first_line = true;
		try {
			std::ifstream stream(filepath);
			stream.exceptions(std::ifstream::badbit);
			while (std::getline(stream, line)) {
				
				if (line == "") {
					continue;
				}

				if (first_line) {
					std::string initial_state_str = line;
					StateT initial_state = ParseStateString<StateT>(line);
					lts.set_initial_state(initial_state);
					first_line = false;
					continue;
				}

				std::string start_state_str, label_str, end_state_str;
				StateT start_state, end_state;
				TransitionT label;

				std::istringstream ss(line);
				std::getline(ss, start_state_str, delimiter);
				std::getline(ss, label_str, delimiter);
				std::getline(ss, end_state_str, delimiter);

				start_state = ParseStateString<StateT>(lts::internal::Trim(start_state_str));
				end_state = ParseStateString<StateT>(lts::internal::Trim(end_state_str));
				label = ParseTransitionString<TransitionT>(lts::internal::Trim(label_str));

				lts.AddTransition(start_state, label, end_state);
			}
		} catch (std::ifstream::failure& e) {
			throw;
		}
	}


}