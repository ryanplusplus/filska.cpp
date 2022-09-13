#include "filska/instruction/Sqr.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Sqr)
{
  InstructionState state{};
};

TEST(Sqr, should_take_the_sqrt_of_m)
{
  state.reg.m = 1.23;
  Sqr().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::sqrt(1.23), state.reg.m, 0.0001);
}
