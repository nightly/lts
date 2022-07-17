#include <gtest/gtest.h>
#include "lts/lts.h"

#include "lts/state.h"
#include "lts/writers.h"

TEST(LTS, Equality) {
	nightly::LTS got;
	nightly::LTS expected;
	got.AddTransition("s0", "a1", "s1");
	expected.AddTransition("s0", "a1", "s1");
	ASSERT_EQ(got, expected);
}

TEST(LTS, NumTransitions) {
	nightly::LTS lts;
	lts.AddTransition("s0", "a1", "s1");
	lts.AddTransition("s1", "a2", "s2");
	lts.AddTransition("s2", "a3", "s0");
	ASSERT_EQ(lts.NumOfTransitions(), 3);
}