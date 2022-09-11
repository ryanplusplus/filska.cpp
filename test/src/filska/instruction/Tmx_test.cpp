#include "filska/instruction/Tmx.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tmx)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Tmx, should_transfer_m_to_x)
{
  program.sub_programs["main"].m = 7;

  auto pc_offset = Tmx().execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(7, program.x);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}
