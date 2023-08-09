#include <gtest/gtest.h>
#include "lts/lts.h"

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

TEST(LTS, Find) {
	nightly::LTS lts;
	lts.AddTransition("s0", "a1", "s1");
	lts.AddTransition("s1", "a2", "s2");
	lts.AddTransition("s2", "a3", "s0");

	ASSERT_EQ(*lts.Find("s0").value(), "s0");
	ASSERT_EQ(lts.Find("s1").has_value(), true);
	ASSERT_EQ(*lts.Find("s1").value(), "s1");
	ASSERT_EQ(*lts.Find("s2").value(), "s2");
	ASSERT_EQ(lts.Find("s3").has_value(), false);
}