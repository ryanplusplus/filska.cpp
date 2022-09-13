#include "filska/instruction/Flr.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Flr)
{
  InstructionState state{};
};

TEST(Flr, should_take_the_floor_of_m)
{
  state.reg.m = 48.3;
  Flr().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::floor(48.3), state.reg.m, 0.0001);
}
