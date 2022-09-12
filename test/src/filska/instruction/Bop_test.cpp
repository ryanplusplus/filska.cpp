#include "filska/instruction/Bop.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Bop)
{
  InstructionState state{};
};

TEST(Bop, should_add)
{
  state.m = 7;
  state.x = 2;

  Bop("add", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(2, state.x);
  CHECK_EQUAL(9, state.y);
  CHECK_EQUAL(7, state.m);
}

TEST(Bop, should_sub)
{
  state.m = 7;
  state.x = 2;

  Bop("sub", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(2, state.x);
  CHECK_EQUAL(-5, state.y);
  CHECK_EQUAL(7, state.m);
}

TEST(Bop, should_mul)
{
  state.m = 7;
  state.x = 2;

  Bop("mul", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(2, state.x);
  CHECK_EQUAL(14, state.y);
  CHECK_EQUAL(7, state.m);
}

TEST(Bop, should_div)
{
  state.m = 7;
  state.x = 2;

  Bop("div", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(2, state.x);
  DOUBLES_EQUAL(2.0 / 7, state.y, 0.0001);
  CHECK_EQUAL(7, state.m);
}

TEST(Bop, should_mod)
{
  state.m = 7;
  state.x = 9;

  Bop("mod", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(9, state.x);
  CHECK_EQUAL(2, state.y);
  CHECK_EQUAL(7, state.m);
}

TEST(Bop, should_pow)
{
  state.x = 2;
  state.y = 4;

  Bop("pow", 'z', 'x', 'y').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
  CHECK_EQUAL(2, state.x);
  CHECK_EQUAL(4, state.y);
  CHECK_EQUAL(16, state.z);
}
