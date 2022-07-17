#include "lts/parsers/state.h"

#include <vector>
#include <string>
#include <string_view>
#include <sstream>

#include "lts/internal/strings.h"

namespace nightly {

	template <>
	std::string ParseStateString(const std::string& str) {
		return str;
	}

	template <>
	std::vector<std::string> ParseStateString(const std::string& str) {
		return lts::internal::StringToVector(str);
	}

	template <>
	std::pair<std::string, std::vector<std::string>> ParseStateString(const std::string& str) {
		constexpr char delimiter = '/';
		std::istringstream ss(str);
		std::string p1, p2_str;
		std::getline(ss, p1, delimiter);
		std::getline(ss, p2_str);
		std::vector<std::string> p2 = lts::internal::StringToVector(p2_str);
		return { p1, p2 };
	}

}