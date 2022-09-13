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
  state.reg.x = 7;

  Txm().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(7, state.reg.x);
  CHECK_EQUAL(7, state.reg.m);
}
