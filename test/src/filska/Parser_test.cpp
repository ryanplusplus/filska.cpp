#include "filska/Parser.hpp"
#include "filska/instruction/all.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(Parser){};

TEST(Parser, should_parse_a_simple_program)
{
  auto program = Program{};
  program.current_sub_program = "main";
  auto main = SubProgram{};
  program.sub_programs["main"] = std::move(main);
  program.sub_programs["main"].instructions.push_back(std::make_unique<Hlt>());

  auto parsed = Parser::parse(R"(
    { main
      hlt
    }
  )");

  CHECK(parsed == program);
}

TEST(Parser, should_parse_a_program_with_multiple_sub_programs)
{
  auto program = Program{};
  program.current_sub_program = "main";
  auto sub = SubProgram{};
  program.sub_programs["sub"] = std::move(sub);
  program.sub_programs["sub"].instructions.push_back(std::make_unique<Ipt>());
  auto main = SubProgram{};
  program.sub_programs["main"] = std::move(main);
  program.sub_programs["main"].instructions.push_back(std::make_unique<Hlt>());

  auto parsed = Parser::parse(R"(
    { sub
      ipt
    }

    { main
      hlt
    }
  )");

  CHECK(parsed == program);
}

TEST(Parser, should_parse_case_insensitively)
{
  auto program = Program{};
  program.current_sub_program = "main";
  auto main = SubProgram{};
  program.sub_programs["main"] = std::move(main);
  program.sub_programs["main"].instructions.push_back(std::make_unique<Hlt>());

  auto parsed = Parser::parse(R"(
    { MAIN
      HLT
    }
  )");

  CHECK(parsed == program);
}

TEST(Parser, should_ignore_comments)
{
  auto program = Program{};
  program.current_sub_program = "main";
  auto main = SubProgram{};
  program.sub_programs["main"] = std::move(main);
  program.sub_programs["main"].instructions.push_back(std::make_unique<Hlt>());

  auto parsed = Parser::parse(R"(
    { main " derp
      hlt "ipt
    }
  )");

  CHECK(parsed == program);
}
