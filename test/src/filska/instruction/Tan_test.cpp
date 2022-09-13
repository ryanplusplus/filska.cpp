#include "filska/instruction/Tan.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tan)
{
  InstructionState state{};
};

TEST(Tan, should_take_the_tan_of_m)
{
  state.reg.m = 1.23;
  Tan().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::tan(1.23), state.reg.m, 0.0001);
}
