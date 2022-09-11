#include <sstream>
#include "filska/instruction/Prt.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Prt)
{
  Program program{};
  std::stringstream output{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Prt, should_print_integers_as_integers)
{
  program.sub_programs["main"].m = -7;
  auto pc_offset = Prt().execute(program, std::cin, output);
  CHECK_EQUAL(1, pc_offset);
  CHECK(output.str() == "-7");
}

TEST(Prt, should_print_floats_as_floats)
{
  program.sub_programs["main"].m = 1.234;
  auto pc_offset = Prt().execute(program, std::cin, output);
  CHECK_EQUAL(1, pc_offset);
  CHECK(output.str() == "1.234");
}
