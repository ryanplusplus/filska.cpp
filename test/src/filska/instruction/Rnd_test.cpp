#include "filska/instruction/Rnd.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Rnd)
{
  InstructionState state{};
};

TEST(Rnd, should_generate_a_random_double_between_0_and_1)
{
  state.reg.m = 0.5;
  Rnd().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(0.5, state.reg.m, 0.5);
}
