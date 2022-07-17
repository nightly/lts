#pragma once

#include <vector>
#include <string>
#include <string_view>

namespace nightly {

	template <typename StateT>
	StateT ParseStateString(const std::string& str);

}