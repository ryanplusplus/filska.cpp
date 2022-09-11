#include <sstream>
#include "filska/instruction/Ipt.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Ipt)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Ipt, should_read_float_from_input_and_write_it_to_m)
{
  auto input = std::stringstream{"1.23"};
  auto pc_offset = Ipt().execute(program, input, std::cout);
  CHECK_EQUAL(1, pc_offset);
  DOUBLES_EQUAL(1.23, program.sub_programs["main"].m, 0.001);
}

TEST(Ipt, should_terminate_if_unable_to_read_a_float_from_input)
{
  auto input = std::stringstream{"derp"};
  auto pc_offset = Ipt().execute(program, input, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_TRUE(program.done);
}
