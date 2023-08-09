#include <gtest/gtest.h>
#include "lts/lts.h"

#include <string>
#include <sstream>

#include "lts/state.h"
#include "lts/writers/writers.h"
#include "lts/writers/styling.h"

// This is non-deterministic with unordered set
TEST(LTS, DISABLED_FinalStates) {
	nightly::LTS<std::string, std::string, std::hash<std::string>> got;
	got.set_initial_state("s0");
	got.AddTransition("s0", "a1", "s1");
	got.AddTransition("s1", "a2", "s2");
	got.AddTransition("s2", "a3", "s3");

	got.AddTransition("s3", "a4", "s4");
	got.AddTransition("s3", "a5", "s5");
	got.AddFinalState("s4");
	got.AddFinalState("s5");
	got.AddTransition("s5", "a6", "s6");

	std::ifstream s1("../../tests/lts/testdata/export_final_states.gv");
	std::stringstream expected_buffer;
	expected_buffer << s1.rdbuf();

	nightly::Styling style;
	nightly::ExportToFile(got, "final_states_test.gv", style, false);
	std::ifstream s2("final_states_test.gv");
	std::stringstream got_buffer;
	got_buffer << s2.rdbuf();

	ASSERT_EQ(got_buffer.str(), expected_buffer.str());
}
