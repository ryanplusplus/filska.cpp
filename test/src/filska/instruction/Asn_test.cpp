#include "filska/instruction/Asn.hpp"
#include "double/InstructionState.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Asn)
{
  InstructionState state{};
};

TEST(Asn, should_take_the_asin_of_m)
{
  state.reg.m = 0.5;
  Asn().execute(state.state, std::cin, std::cout);
  CHECK_EQUAL(1, state.reg.pc);
  DOUBLES_EQUAL(std::asin(0.5), state.reg.m, 0.0001);
}
