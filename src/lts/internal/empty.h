#pragma once

#include <utility>

namespace nightly {

    template <class T1, class T2>
    bool empty(const std::pair<T1, T2>& p) {
        return p == std::pair<T1, T2>();
    }

}