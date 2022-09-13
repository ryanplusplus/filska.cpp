#include "filska/instruction/Neg.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Neg)
{
  InstructionState state{};
};

TEST(Neg, should_negate_m)
{
  state.reg.m = 1.23;
  Neg().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(-1.23, state.reg.m, 0.0001);
}
