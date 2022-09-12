#include <sstream>
#include "filska/instruction/Prt.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Prt)
{
  InstructionState state{};
  std::stringstream output{};
};

TEST(Prt, should_print_integers_as_integers)
{
  state.m = -7;
  Prt().execute(state.state, std::cin, output);
  CHECK_EQUAL(1, state.pc);
  CHECK(output.str() == "-7");
}

TEST(Prt, should_print_floats_as_floats)
{
  state.m = 1.234;
  Prt().execute(state.state, std::cin, output);
  CHECK_EQUAL(1, state.pc);
  CHECK(output.str() == "1.234");
}
