#include "filska/instruction/Jmp.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Jmp)
{
  InstructionState state{};
};

TEST(Jmp, should_jump_to_another_sub_program)
{
  Jmp("blah").execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_TRUE(state.current_sub_program == "blah");
}
