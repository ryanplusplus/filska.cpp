#include "filska/instruction/Cos.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Cos)
{
  InstructionState state{};
};

TEST(Cos, should_take_the_cos_of_m)
{
  state.reg.m = 1.23;
  Cos().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::cos(1.23), state.reg.m, 0.0001);
}
