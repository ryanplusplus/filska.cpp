#include "filska/instruction/Tst.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tst)
{
  InstructionState state{};
};

TEST(Tst, should_increment_pc_when_flag_is_not_set)
{
  state.flag.z = false;
  Tst('z', 10).execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
}

TEST(Tst, should_offset_the_pc_when_the_flag_is_set)
{
  state.reg.pc = 10;
  state.flag.l = true;
  Tst('l', -5).execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(5, state.reg.pc);
}
