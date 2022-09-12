#include "filska/instruction/Hlt.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Hlt)
{
  InstructionState state{};
};

TEST(Hlt, should_terminate_program)
{
  Hlt().execute(state.state, std::cin, std::cout);
  CHECK_TRUE(state.done);
}
