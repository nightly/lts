#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "lts/lts.h"
#include "lts/state.h"
#include "lts/internal/empty.h"
#include "lts/writers/styling.h"

namespace nightly {


	// ========================================
	// LTS & State Ofstream & GraphViz
	// ========================================

	template <typename KeyT, typename TransitionT>
	void PrintGraphVizState(std::ofstream& os, const nightly::State<KeyT, TransitionT>& state, const KeyT& name) {
		if (state.IsEmpty()) {
			os << "	\"";
			os << name << "\"\n";
			return;
		}
		for (const auto& t : state.transitions_) {
			os << "	" << "\"";
			os << name << "\" -> \"";
			os << t.to() << "\"" << " [label = " << "<";
			os << t.label() << ">];\n";
		}
	}

	template <typename StateT>
	void WriteXLabel(const StateT& state, std::ostream& os) {}

	template <typename KeyT, typename TransitionT, typename HashF>
	void PrintGraphVizLTS(std::ofstream& os, const LTS<KeyT, TransitionT, HashF>& lts, const Styling& style, bool write_x_label = false) {
		os << style.type << " {\n";
		os << "	" << style.FontStr(style.font_names) << "\n";
		os << "	node " << "[" << style.FontStr(style.node_fonts) << "]\n";
		os << "	edge " << "[" << style.FontStr(style.edge_fonts) << "]\n";
		os << "	rankdir=" << style.rank_dir << ";\n";
		os << "	forcelabels=true;\n";

		// Initial states
		os << "	" << style.initial_nodes << ";\n";
		os << "	" << "<";
		os << lts.initial_state() << ">" << ";\n";

		// X labels
		if (write_x_label) {
			for (const auto& pair : lts.states()) {
				os << "	\"";
				os << pair.first << "\"" << " [xlabel=";
				WriteXLabel<KeyT>(pair.first, os);
				os << "]\n";
			}
		}

		// Final states
		if (!lts.final_states().empty()) {
			os << "	" << style.final_nodes << ";\n";
			for (const auto& s : lts.final_states()) {
				os << "	" << "<";
				os<< s << ">" << ";\n";
			}
		}

		// Edge styling
		if (style.edge != "edge []") {
			os << "	" << style.edge << ";\n";
		}

		// Regular states and transitions
		os << "	" << style.regular_nodes << ";\n";
		for (const auto& pair : lts.states()) {
			PrintGraphVizState(os, pair.second, pair.first);
		}
		os << "}";
	}

	template <typename _KeyT, typename _TransitionT, typename _HashF>
	std::ofstream& operator<<(std::ofstream& os, const LTS<_KeyT, _TransitionT, _HashF>& lts) {
		nightly::Styling style;
		PrintGraphVizLTS(os, lts, style);
	}
}