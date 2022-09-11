#include "filska/instruction/Tym.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tym)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Tym, should_transfer_y_to_m)
{
  program.y = 7;

  auto pc_offset = Tym().execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(7, program.y);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}
