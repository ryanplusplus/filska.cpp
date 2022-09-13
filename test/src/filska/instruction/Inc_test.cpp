#include "filska/instruction/Inc.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Inc)
{
  InstructionState state{};
};

TEST(Inc, should_increment_m)
{
  state.reg.m = 1.23;
  Inc().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(2.23, state.reg.m, 0.0001);
}
