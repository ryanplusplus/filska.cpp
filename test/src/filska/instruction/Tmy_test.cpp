#include "filska/instruction/Tmy.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Tmy)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Tmy, should_transfer_m_to_y)
{
  program.sub_programs["main"].m = 7;

  auto pc_offset = Tmy().execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(7, program.y);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}
