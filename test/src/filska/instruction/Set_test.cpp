#include "filska/instruction/Set.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Set)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Set, should_set_m)
{
  auto pc_offset = Set(1.23).execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  DOUBLES_EQUAL(1.23, program.sub_programs["main"].m, 0.001);
}
