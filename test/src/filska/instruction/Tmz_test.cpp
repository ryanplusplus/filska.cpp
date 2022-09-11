#include "filska/instruction/Tmz.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tmz)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Tmz, should_transfer_m_to_z)
{
  program.sub_programs["main"].m = 7;

  auto pc_offset = Tmz().execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(7, program.z);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}
