#include "filska/instruction/Tym.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tym)
{
  InstructionState state{};
};

TEST(Tym, should_transfer_y_to_m)
{
  state.reg.y = 7;

  Tym().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(7, state.reg.y);
  CHECK_EQUAL(7, state.reg.m);
}
