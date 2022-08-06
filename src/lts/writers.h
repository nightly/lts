#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "lts/lts.h"
#include "lts/state.h"
#include "lts/internal/empty.h"

namespace nightly {


	// =========================
	// Generic structure output
	// =========================


	/**
	* @brief std::vector operator<< overload delimited by commas
	*/
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
		for (std::size_t i = 0; i < vec.size(); ++i) {
			os << vec[i];
			if (i != vec.size() - 1) {
				os << ",";
			}
		}
		return os;
	}

	/**
	 * @brief std::pair operator<<
	 */
	template <typename T, typename U>
	std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& pair) {
		os << pair.first;
		os << ": ";
		os << pair.second;
		return os;
	}

	// ========================================
	// LTS & State Ofstream & GraphViz
	// ========================================

	template <typename KeyT, typename TransitionT>
	void PrintGraphVizState(std::ofstream& os, const nightly::State<KeyT, TransitionT>& state, const KeyT& name) {
		if (state.IsEmpty()) {
			os << "	" << "\"" << name << "\"" << "\n";
			return;
		}
		for (const auto& t : state.transitions_) {
			os << "	" << "\"" << name << "\"" << " -> " << "\"" << t.to() << "\"" << " [label = " << "<";
			os << t.label() << ">];\n";
		}
	}

	template <typename KeyT, typename TransitionT, typename HashF>
	void PrintGraphVizLTS(std::ofstream& os, const LTS<KeyT, TransitionT, HashF>& lts, const std::string& font, bool font_check) {
		std::string font_str = "fontname=\"" + font;
		if (font_check) {
			font_str += ", Ink Free";
		}
		font_str += ", Helvetica, Arial, sans - serif\"";

		os << "digraph finite_state_machine {\n";
		os << "	" << font_str << "\n";
		os << "	node " << "[" << font_str << "]\n";
		os << "	edge " << "[" << font_str << "]\n";
		os << "	rankdir=LR;\n";
		os << "	node [shape = doublecircle];\n";
		os << "	" << "<" << lts.initial_state() << ">" << ";\n";
		os << "	node [shape = circle];\n";
		for (const auto& pair : lts.states()) {
			PrintGraphVizState(os, pair.second, pair.first);
		}
		os << "}";
	}

	template <typename KeyT, typename TransitionT, typename HashF>
	std::ofstream& operator<<(std::ofstream& os, const LTS<KeyT, TransitionT, HashF>& lts) {
		PrintGraphVizLTS(os, lts, "Helvetica Neue", false);
		return os;
	}

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