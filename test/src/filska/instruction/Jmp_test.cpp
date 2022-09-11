#include "filska/instruction/Jmp.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Jmp){};

TEST(Jmp, should_jump_to_another_sub_program)
{
  auto program = Program{};
  auto pc_offset = Jmp("blah").execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_TRUE(program.current_sub_program == "blah");
}
