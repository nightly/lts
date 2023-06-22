#pragma once

#include <string>
#include <ostream>
#include <iostream>

#include "lts/lts.h"
#include "lts/state.h"
#include "lts/internal/empty.h"
#include "lts/writers/generic.h"

namespace nightly {

	// ========================================
	// LTS & State Ostream
	// ========================================

	template <typename KeyT, typename TransitionT>
	void PrintState(std::ostream& os, const nightly::State<KeyT, TransitionT>& state, const KeyT& name) {
		os << "State name: " << name << '\n';
		if (state.transitions_.empty()) {
			os << "  With 0 transitions" << '\n';
			return;
		}
		os << "  Transitions: " << '\n';
		for (const auto& pair : state.transitions_) {
			os << "    Label: " << pair.label() << " " << "End State: " << pair.to() << '\n';
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