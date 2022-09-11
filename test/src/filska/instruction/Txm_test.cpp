#include "filska/instruction/Txm.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Txm)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Txm, should_transfer_x_to_m)
{
  program.x = 7;

  auto pc_offset = Txm().execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(7, program.x);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}
