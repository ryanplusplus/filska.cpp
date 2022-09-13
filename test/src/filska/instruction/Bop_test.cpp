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
  state.reg.m = 7;
  state.reg.x = 2;

  Bop("add", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(2, state.reg.x);
  CHECK_EQUAL(9, state.reg.y);
  CHECK_EQUAL(7, state.reg.m);
}

TEST(Bop, should_sub)
{
  state.reg.m = 7;
  state.reg.x = 2;

  Bop("sub", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(2, state.reg.x);
  CHECK_EQUAL(-5, state.reg.y);
  CHECK_EQUAL(7, state.reg.m);
}

TEST(Bop, should_mul)
{
  state.reg.m = 7;
  state.reg.x = 2;

  Bop("mul", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(2, state.reg.x);
  CHECK_EQUAL(14, state.reg.y);
  CHECK_EQUAL(7, state.reg.m);
}

TEST(Bop, should_div)
{
  state.reg.m = 7;
  state.reg.x = 2;

  Bop("div", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(2, state.reg.x);
  DOUBLES_EQUAL(2.0 / 7, state.reg.y, 0.0001);
  CHECK_EQUAL(7, state.reg.m);
}

TEST(Bop, should_mod)
{
  state.reg.m = 7;
  state.reg.x = 9;

  Bop("mod", 'y', 'x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(9, state.reg.x);
  CHECK_EQUAL(2, state.reg.y);
  CHECK_EQUAL(7, state.reg.m);
}

TEST(Bop, should_pow)
{
  state.reg.x = 2;
  state.reg.y = 4;

  Bop("pow", 'z', 'x', 'y').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK_EQUAL(2, state.reg.x);
  CHECK_EQUAL(4, state.reg.y);
  CHECK_EQUAL(16, state.reg.z);
}
