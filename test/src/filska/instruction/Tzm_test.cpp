#include "filska/instruction/Tzm.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tzm)
{
  InstructionState state{};
};

TEST(Tzm, should_transfer_z_to_m)
{
  state.reg.z = 7;

  Tzm().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(7, state.reg.z);
  CHECK_EQUAL(7, state.reg.m);
}
