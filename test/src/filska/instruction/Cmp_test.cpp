#include "filska/instruction/Cmp.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Cmp)
{
  InstructionState state{};
};

TEST(Cmp, should_increment_pc)
{
  Cmp('x').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
}

TEST(Cmp, should_set_zero_flag_when_m_is_zero)
{
  state.reg.m = 0;
  Cmp('x').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(true, state.flag.z);

  state.reg.m = 1;
  Cmp('x').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(false, state.flag.z);

  state.reg.m = -1;
  Cmp('x').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(false, state.flag.z);
}

TEST(Cmp, should_update_l_and_g_and_e_flags)
{
  state.reg.x = 3;
  state.reg.m = 2;
  Cmp('x').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(true, state.flag.l);
  CHECK_EQUAL(false, state.flag.g);
  CHECK_EQUAL(false, state.flag.e);

  state.reg.z = 2;
  state.reg.m = 2;
  Cmp('z').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(false, state.flag.l);
  CHECK_EQUAL(false, state.flag.g);
  CHECK_EQUAL(true, state.flag.e);

  state.reg.y = 1;
  state.reg.m = 2;
  Cmp('y').execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(false, state.flag.l);
  CHECK_EQUAL(true, state.flag.g);
  CHECK_EQUAL(false, state.flag.e);
}
