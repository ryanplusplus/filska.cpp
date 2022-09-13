#include "filska/instruction/Sin.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Sin)
{
  InstructionState state{};
};

TEST(Sin, should_take_the_sin_of_m)
{
  state.reg.m = 1.23;
  Sin().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::sin(1.23), state.reg.m, 0.0001);
}
