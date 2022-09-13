#include <sstream>
#include "filska/instruction/Chr.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Chr)
{
  InstructionState state{};
  std::stringstream output{};
};

TEST(Chr, should_print_m_as_a_char)
{
  state.reg.m = 'D' + 0.5;
  Chr().execute(state.state, std::cin, output);
  CHECK_EQUAL(1, state.reg.pc);
  CHECK(output.str() == "D");
}
