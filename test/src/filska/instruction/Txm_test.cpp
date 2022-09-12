#include "filska/instruction/Txm.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Txm)
{
  InstructionState state{};
};

TEST(Txm, should_transfer_x_to_m)
{
  state.x = 7;

  Txm().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(7, state.x);
  CHECK_EQUAL(7, state.m);
}
