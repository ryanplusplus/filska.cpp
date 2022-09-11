#include "filska/InstructionParser.hpp"
#include "filska/instruction/all.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using namespace filska;
using namespace filska::instruction;

TEST_GROUP(InstructionParser)
{
  int dummy;

  template <typename T>
  void should_parse_to(std::string && s, T && expected)
  {
    auto instruction = InstructionParser::parse(s);
    CHECK(*instruction.get() == expected);
  }

  template <typename T, typename F>
  void should_throw(F thunk)
  {
    try {
      thunk();
    }
    catch(T& e) {
      return;
    }

    FAIL("Didn't throw");
  }
};

TEST(InstructionParser, should_throw_if_instruction_is_unknown)
{
  should_throw<std::invalid_argument>([] {
    InstructionParser::parse("derp");
  });
}

TEST(InstructionParser, should_parse_gto)
{
  should_parse_to("gto,-42", Gto(-42));
}

TEST(InstructionParser, should_parse_hlt)
{
  should_parse_to("hlt", Hlt());
}

TEST(InstructionParser, should_parse_ipt)
{
  should_parse_to("ipt", Ipt());
}

TEST(InstructionParser, should_parse_jmp)
{
  should_parse_to("jmp,foo", Jmp("foo"));
}

TEST(InstructionParser, should_parse_jpr)
{
  should_parse_to("jpr,foo", Jpr("foo"));
}

TEST(InstructionParser, should_parse_prt)
{
  should_parse_to("prt", Prt());
}

TEST(InstructionParser, should_parse_set)
{
  should_parse_to("set,1.23", Set(1.23));
}

TEST(InstructionParser, should_parse_swp)
{
  should_parse_to("swp,xy", Swp('x', 'y'));
}

TEST(InstructionParser, should_parse_tmx)
{
  should_parse_to("tmx", Tmx());
}

TEST(InstructionParser, should_parse_tmy)
{
  should_parse_to("tmy", Tmy());
}

TEST(InstructionParser, should_parse_tmz)
{
  should_parse_to("tmz", Tmz());
}

TEST(InstructionParser, should_parse_txm)
{
  should_parse_to("txm", Txm());
}

TEST(InstructionParser, should_parse_tym)
{
  should_parse_to("tym", Tym());
}

TEST(InstructionParser, should_parse_tzm)
{
  should_parse_to("tzm", Tzm());
}
