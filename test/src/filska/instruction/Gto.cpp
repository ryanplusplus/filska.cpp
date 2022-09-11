#include "filska/instruction/Gto.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Gto){};

TEST(Gto, should_jump_within_the_current_sub_program)
{
  auto program = Program{};
  auto pc_offset = Gto(42).execute(program, std::cin, std::cout);
  CHECK_EQUAL(42, pc_offset);
}
