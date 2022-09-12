#include "filska/instruction/Gto.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Gto)
{
  InstructionState state{};
};

TEST(Gto, should_jump_within_the_current_sub_program)
{
  Gto(42).execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(42, state.pc);
}
