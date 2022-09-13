#include "filska/instruction/Exp.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Exp)
{
  InstructionState state{};
};

TEST(Exp, should_take_the_exp_of_m)
{
  state.reg.m = 48.3;
  Exp().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::exp(48.3), state.reg.m, 0.0001);
}
