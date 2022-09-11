#include <sstream>
#include "filska/Parser.hpp"
#include "filska/Vm.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;

TEST_GROUP(Vm)
{
  std::stringstream input{};
  std::stringstream output{};

  void given_that_input_contains(const char* s)
  {
    input << s;
  }

  void output_should_contain(const char* s)
  {
    STRCMP_EQUAL(s, output.str().c_str());
  }

  void after_program_runs(const char* s)
  {
    auto program = Parser::parse(s);
    Vm::run(program, input, output);
  }
};

TEST(Vm, should_run_a_simple_program)
{
  given_that_input_contains("4 2");
  after_program_runs(R"(
    { main
      ipt
      prt
      ipt
      prt
      hlt
    }
  )");
  output_should_contain("42");
}

TEST(Vm, should_handle_pc_wraparound)
{
  given_that_input_contains("7");
  after_program_runs(R"(
    { main
      ipt
      gto,7
      hlt
      prt
      hlt
    }
  )");
  output_should_contain("7");
}
