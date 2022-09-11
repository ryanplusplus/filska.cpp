#include "filska/instruction/Swp.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Swp)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Swp, should_increment_pc)
{
  program.sub_programs["main"].m = 7;

  auto pc_offset = Swp('x', 'y').execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
}

TEST(Swp, should_swap_x)
{
  auto& m = program.sub_programs["main"].m;
  auto& x = program.x;

  m = 11;
  x = 7;

  Swp('x', 'm').execute(program, std::cin, std::cout);
  CHECK_EQUAL(11, x);
  CHECK_EQUAL(7, m);
}

TEST(Swp, should_swap_y)
{
  auto& m = program.sub_programs["main"].m;
  auto& y = program.y;

  m = 11;
  y = 7;

  Swp('y', 'm').execute(program, std::cin, std::cout);
  CHECK_EQUAL(11, y);
  CHECK_EQUAL(7, m);
}

TEST(Swp, should_swap_z)
{
  auto& m = program.sub_programs["main"].m;
  auto& z = program.z;

  m = 11;
  z = 7;

  Swp('z', 'm').execute(program, std::cin, std::cout);
  CHECK_EQUAL(11, z);
  CHECK_EQUAL(7, m);
}

TEST(Swp, should_swap_m)
{
  auto& m = program.sub_programs["main"].m;
  auto& x = program.x;

  m = 11;
  x = 7;

  Swp('m', 'x').execute(program, std::cin, std::cout);
  CHECK_EQUAL(7, m);
  CHECK_EQUAL(11, x);
}
