#include <sstream>
#include "filska/instruction/Ipt.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Ipt)
{
  InstructionState state{};
  std::stringstream input{};
};

TEST(Ipt, should_read_float_from_input_and_write_it_to_m)
{
  input << "1.23";
  Ipt().execute(state.state, input, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(1.23, state.reg.m, 0.0001);
  CHECK_FALSE(state.done);
}

TEST(Ipt, should_terminate_if_unable_to_read_a_float_from_input)
{
  input << "derp";
  Ipt().execute(state.state, input, std::cout);
  CHECK_TRUE(state.done);
}
