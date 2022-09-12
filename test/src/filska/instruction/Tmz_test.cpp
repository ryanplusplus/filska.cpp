#include "filska/instruction/Tmz.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tmz)
{
  InstructionState state{};
};

TEST(Tmz, should_transfer_m_to_z)
{
  state.m = 7;

  Tmz().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(7, state.z);
  CHECK_EQUAL(7, state.m);
}
