#include "lts/parsers/transition.h"

#include <vector>
#include <string>
#include <string_view>
#include <sstream>

#include "lts/internal/strings.h"

namespace nightly {

	template <>
	std::string ParseTransitionString(const std::string& str) {
		return str;
	}

	template <> 
	std::pair<size_t, std::string> ParseTransitionString(const std::string& str) {
		std::string n;
		std::string action;

		std::stringstream ss(str);
		std::getline(ss, n, '/');
		std::getline(ss, action);

		return { stoul(n), action};
	}

	template<>
	std::vector<std::string> ParseTransitionString(const std::string& str) {
		return lts::internal::StringToVector(str);
	}

}