#include "filska/instruction/Swp.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Swp)
{
  InstructionState state{};
};

TEST(Swp, should_increment_pc)
{
  state.reg.m = 7;
  Swp('x', 'y').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
}

TEST(Swp, should_swap_x)
{
  state.reg.m = 11;
  state.reg.x = 7;

  Swp('x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(11, state.reg.x);
  CHECK_EQUAL(7, state.reg.m);
}

TEST(Swp, should_swap_y)
{
  state.reg.m = 11;
  state.reg.y = 7;

  Swp('y', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(11, state.reg.y);
  CHECK_EQUAL(7, state.reg.m);
}

TEST(Swp, should_swap_z)
{
  state.reg.m = 11;
  state.reg.z = 7;

  Swp('z', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(11, state.reg.z);
  CHECK_EQUAL(7, state.reg.m);
}

TEST(Swp, should_swap_m)
{
  state.reg.m = 11;
  state.reg.x = 7;

  Swp('m', 'x').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(7, state.reg.m);
  CHECK_EQUAL(11, state.reg.x);
}
