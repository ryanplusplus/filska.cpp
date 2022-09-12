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
  state.y = 7;

  Tym().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(7, state.y);
  CHECK_EQUAL(7, state.m);
}
