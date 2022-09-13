#include "filska/instruction/Log.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Log)
{
  InstructionState state{};
};

TEST(Log, should_take_the_log_of_m)
{
  state.reg.m = 48.3;
  Log().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::log10(48.3), state.reg.m, 0.0001);
}
