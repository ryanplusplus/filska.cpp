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
  state.z = 7;

  Tzm().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(7, state.z);
  CHECK_EQUAL(7, state.m);
}
