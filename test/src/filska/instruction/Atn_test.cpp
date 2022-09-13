#include "filska/instruction/Atn.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Atn)
{
  InstructionState state{};
};

TEST(Atn, should_take_the_atan_of_m)
{
  state.reg.m = 1.23;
  Atn().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::atan(1.23), state.reg.m, 0.0001);
}
