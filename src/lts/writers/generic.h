#pragma once

#include <string>
#include <ostream>
#include <vector>

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

}