#include "filska/instruction/Tmy.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tmy)
{
  InstructionState state{};
};

TEST(Tmy, should_transfer_m_to_y)
{
  state.m = 7;

  Tmy().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(7, state.y);
  CHECK_EQUAL(7, state.m);
}
