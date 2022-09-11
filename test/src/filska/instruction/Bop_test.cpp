#include "filska/instruction/Bop.hpp"
#include "filska/Program.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Bop)
{
  Program program{};

  void setup()
  {
    program.current_sub_program = "main";
    auto main = SubProgram{};
    program.sub_programs["main"] = std::move(main);
  }
};

TEST(Bop, should_add)
{
  program.sub_programs["main"].m = 7;
  program.x = 2;

  auto pc_offset = Bop("add", 'y', 'x', 'm').execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(2, program.x);
  CHECK_EQUAL(9, program.y);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}

TEST(Bop, should_sub)
{
  program.sub_programs["main"].m = 7;
  program.x = 2;

  auto pc_offset = Bop("sub", 'y', 'x', 'm').execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(2, program.x);
  CHECK_EQUAL(-5, program.y);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}

TEST(Bop, should_mul)
{
  program.sub_programs["main"].m = 7;
  program.x = 2;

  auto pc_offset = Bop("mul", 'y', 'x', 'm').execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(2, program.x);
  CHECK_EQUAL(14, program.y);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}

TEST(Bop, should_div)
{
  program.sub_programs["main"].m = 7;
  program.x = 2;

  auto pc_offset = Bop("div", 'y', 'x', 'm').execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(2, program.x);
  DOUBLES_EQUAL(2.0 / 7, program.y, 0.0001);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}

TEST(Bop, should_mod)
{
  program.sub_programs["main"].m = 7;
  program.x = 9;

  auto pc_offset = Bop("mod", 'y', 'x', 'm').execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(9, program.x);
  CHECK_EQUAL(2, program.y);
  CHECK_EQUAL(7, program.sub_programs["main"].m);
}

TEST(Bop, should_pow)
{
  program.x = 2;
  program.y = 4;

  auto pc_offset = Bop("pow", 'z', 'x', 'y').execute(program, std::cin, std::cout);
  CHECK_EQUAL(1, pc_offset);
  CHECK_EQUAL(2, program.x);
  CHECK_EQUAL(4, program.y);
  CHECK_EQUAL(16, program.z);
}
