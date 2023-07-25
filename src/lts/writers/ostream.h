#pragma once

#include <string>
#include <ostream>
#include <iostream>

#include "lts/lts.h"
#include "lts/state.h"
#include "lts/internal/empty.h"

namespace nightly {

	// ========================================
	// LTS & State Ostream
	// ========================================

	template <typename T>
	static std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
		os << "[";
		for (std::size_t i = 0; i < vec.size(); ++i) {
			os << vec[i];
			if (i != vec.size() - 1) {
				os << ", ";
			}
		}
		os << "]";
		return os;
	}

	template <typename KeyT, typename TransitionT>
	void PrintState(std::ostream& os, const nightly::State<KeyT, TransitionT>& state, const KeyT& name) {
		os << "State: " << name << '\n';
		if (state.transitions_.empty()) {
			os << "  With no transitions" << '\n';
			return;
		}
		for (const auto& pair : state.transitions_) {
			os << "  Label: " << pair.label() << " -> " << pair.to() << '\n';
		}
	}

	template <typename KeyT, typename TransitionT, typename HashF>
	std::ostream& operator<<(std::ostream& os, const LTS<KeyT, TransitionT, HashF>& lts) {
		if (lts.states_.empty()) {
			os << "Empty Labelled Transition System\n";
			return os;
		}
		os << "Initial state: " << lts.initial_state() << '\n';
		for (const auto& pair : lts.states()) {
			PrintState(os, pair.second, pair.first);
		}
		return os;
	}


}