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
  state.reg.m = 7;

  Tmz().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(7, state.reg.z);
  CHECK_EQUAL(7, state.reg.m);
}
