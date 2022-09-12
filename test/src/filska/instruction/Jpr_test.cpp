#include "filska/instruction/Jpr.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Jpr)
{
  InstructionState state{};
};

TEST(Jpr, should_jump_to_another_sub_program_and_reset_the_pc)
{
  state.pc = 123;
  Jpr("blah").execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(0, state.pc);
  CHECK_TRUE(state.current_sub_program == "blah");
}
