#include "lts/parsers/parsers.h"
#include <gtest/gtest.h>

#include <string>
#include <filesystem>

#include "lts/lts.h"
#include "lts/writers.h"
#include "lts/internal/directory.h"

TEST(ParseLTS, LTS1) {
	nightly::LTS got;
	nightly::ReadFromFile(got, "../../tests/lts/testdata/lts1.txt");

	nightly::LTS expected;
	expected.set_initial_state("s0");
	expected.AddTransition("s0", "a1", "s1");
	expected.AddTransition("s1", "a2", "s2");

	ASSERT_EQ(got, expected);
}

TEST(ParseLTS, LTS1_JSON) {
	nightly::LTS got;
	nightly::ReadFromJsonFile(got, "../../tests/lts/testdata/lts1.json");

	nightly::LTS expected;
	expected.set_initial_state("s0");
	expected.AddTransition("s0", "a1", "s1");
	expected.AddTransition("s1", "a2", "s2");

	ASSERT_EQ(got, expected);
}