#include "filska/instruction/Dec.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Dec)
{
  InstructionState state{};
};

TEST(Dec, should_decrement_m)
{
  state.reg.m = 1.23;
  Dec().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(0.23, state.reg.m, 0.0001);
}
