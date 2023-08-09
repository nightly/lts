#pragma once 

#include <string>
#include <vector>
#include <ostream>
#include <fstream>
#include <utility>

#include "lts/transition.h"

#include <ankerl/unordered_dense.h>

namespace nightly {

	template <typename KeyT = std::string, typename TransitionT = std::string>
	class State {
	public:
		ankerl::unordered_dense::set<Transition<KeyT, TransitionT>> transitions_;
	public:

		/** 
		 * @tparam KeyT: the data type used to defined keys/state names. E.g std::string, std::vector<std::string>
		 * @tparam TransitionT : defines the data type used to represent transitions. E.g. std::string, CompositeOperation 
		 */
		State() = default;
		~State() = default;

		ankerl::unordered_dense::set<Transition<KeyT, TransitionT>>& transitions() {
			return transitions_;
		}

		const ankerl::unordered_dense::set<Transition<KeyT, TransitionT>>& transitions() const {
			return transitions_;
		}

		void AddTransition(const TransitionT& label, const KeyT& end_state) {
			transitions_.emplace(label, end_state);
		}

		bool TransitionExists(const TransitionT& label, const KeyT& end_state) const {
			return transitions_.contains(Transition(label, end_state));
		}

		bool IsEmpty() const {
			return transitions_.empty();
		}

		bool operator==(const State& other) const {
			return (transitions_ == other.transitions_);
		}

		template <typename _KeyT, typename _TransitionT>
		friend std::ostream& operator<<(std::ostream& os, const State& state);

		template <typename _KeyT, typename _TransitionT>
		friend std::ofstream& operator<<(std::ofstream& os, const State& state);
	};

}
