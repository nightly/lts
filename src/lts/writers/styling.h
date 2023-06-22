#pragma once

#include <string>
#include <string_view>

namespace nightly {

	struct Styling {
	public:
		std::string type = "digraph finite_state_machine";
		std::string rank_dir = "LR";

		std::string font_names = "Helvetica Neue, Helvetica, Arial, sans - serif";
		std::string node_fonts = "Helvetica Neue, Helvetica, Arial, sans - serif";
		std::string edge_fonts = "Helvetica Neue, Helvetica, Arial, sans - serif";
		
		std::string edge = "edge []";

		std::string initial_nodes = "node [shape = doublecircle]";
		std::string regular_nodes = "node [shape = circle]";
		std::string final_nodes = "node [shape = Mcircle]";

	public:
		void SetFont(const std::string& font, bool font_check = true) {
			std::string font_str = "fontname=\"" + font;
			if (font_check) {
				font_str += ", Ink Free";
			}
			font_str += ", Helvetica, Arial, sans - serif\"";
			
			font_names = font_str;
			node_fonts = font_str;
			edge_fonts = font_str;
		}

		static std::string FontStr(std::string_view font_list) {
			std::string ret;
			ret += "fontname=\"";
			ret += font_list;
			ret += "\"";
			return ret;
		}

	};

}