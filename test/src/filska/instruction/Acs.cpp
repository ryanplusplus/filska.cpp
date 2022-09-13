#include "filska/instruction/Acs.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Acs)
{
  InstructionState state{};
};

TEST(Acs, should_take_the_acos_of_m)
{
  state.reg.m = 0.5;
  Acs().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::acos(0.5), state.reg.m, 0.0001);
}
