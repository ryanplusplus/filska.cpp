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
  state.m = 7;
  Swp('x', 'y').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.pc);
}

TEST(Swp, should_swap_x)
{
  state.m = 11;
  state.x = 7;

  Swp('x', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(11, state.x);
  CHECK_EQUAL(7, state.m);
}

TEST(Swp, should_swap_y)
{
  state.m = 11;
  state.y = 7;

  Swp('y', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(11, state.y);
  CHECK_EQUAL(7, state.m);
}

TEST(Swp, should_swap_z)
{
  state.m = 11;
  state.z = 7;

  Swp('z', 'm').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(11, state.z);
  CHECK_EQUAL(7, state.m);
}

TEST(Swp, should_swap_m)
{
  state.m = 11;
  state.x = 7;

  Swp('m', 'x').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(7, state.m);
  CHECK_EQUAL(11, state.x);
}
