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
  state.m = 7;

  Tmx().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(7, state.x);
  CHECK_EQUAL(7, state.m);
}
