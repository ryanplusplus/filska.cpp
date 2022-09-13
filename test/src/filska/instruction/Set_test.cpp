#include "filska/instruction/Set.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Set)
{
  InstructionState state{};
};

TEST(Set, should_set_m)
{
  Set(1.23).execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(1.23, state.reg.m, 0.0001);
}
