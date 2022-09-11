#include "filska/instruction/Hlt.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Hlt){};

TEST(Hlt, should_terminate_program)
{
  auto program = Program{};
  auto pc_offset = Hlt().execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_TRUE(program.done);
}
