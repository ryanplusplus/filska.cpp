#include "filska/instruction/Jpr.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Jpr){};

TEST(Jpr, should_jump_to_another_sub_program_and_reset_the_pc)
{
  auto program = Program{};
  program.current_sub_program = "main";
  auto main = SubProgram{};
  main.pc = 123;
  program.sub_programs["main"] = std::move(main);

  auto pc_offset = Jpr("blah").execute(program, std::cin, std::cout);
  CHECK_EQUAL(-123, pc_offset);
  CHECK_TRUE(program.current_sub_program == "blah");
}
