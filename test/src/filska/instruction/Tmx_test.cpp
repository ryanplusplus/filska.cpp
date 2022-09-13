#include "filska/instruction/Tmx.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tmx)
{
  InstructionState state{};
};

TEST(Tmx, should_transfer_m_to_x)
{
  state.reg.m = 7;

  Tmx().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(7, state.reg.x);
  CHECK_EQUAL(7, state.reg.m);
}
