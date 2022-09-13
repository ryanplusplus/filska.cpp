#include "filska/InstructionParser.hpp"
#include "filska/instruction/all.hpp"

using namespace filska;
using namespace filska::instruction;

std::unique_ptr<Instruction> InstructionParser::parse(std::string s)
{
  if(s.starts_with("add") ||
    s.starts_with("sub") ||
    s.starts_with("mul") ||
    s.starts_with("div") ||
    s.starts_with("mod") ||
    s.starts_with("pow")) {
    return std::make_unique<Bop>(s.substr(0, 3), s[4], s[6], s[7]);
  }
  else if(s.starts_with("chr")) {
    return std::make_unique<Chr>();
  }
  else if(s.starts_with("cmp")) {
    return std::make_unique<Cmp>(s[4]);
  }
  else if(s.starts_with("gto")) {
    return std::make_unique<Gto>(std::stol(s.substr(4)));
  }
  else if(s == "hlt") {
    return std::make_unique<Hlt>();
  }
  else if(s == "ipt") {
    return std::make_unique<Ipt>();
  }
  else if(s.starts_with("jmp")) {
    return std::make_unique<Jmp>(s.substr(4));
  }
  else if(s.starts_with("jpr")) {
    return std::make_unique<Jpr>(s.substr(4));
  }
  else if(s == "prt") {
    return std::make_unique<Prt>();
  }
  else if(s.starts_with("set")) {
    return std::make_unique<Set>(std::stof(s.substr(4)));
  }
  else if(s.starts_with("swp")) {
    return std::make_unique<Swp>(s[4], s[5]);
  }
  else if(s == "tmx") {
    return std::make_unique<Tmx>();
  }
  else if(s == "tmy") {
    return std::make_unique<Tmy>();
  }
  else if(s == "tmz") {
    return std::make_unique<Tmz>();
  }
  else if(s.starts_with("tst")) {
    return std::make_unique<Tst>(s[4], std::stol(s.substr(6)));
  }
  else if(s == "txm") {
    return std::make_unique<Txm>();
  }
  else if(s == "tym") {
    return std::make_unique<Tym>();
  }
  else if(s == "tzm") {
    return std::make_unique<Tzm>();
  }

  throw std::invalid_argument("Unknown instruction");
}
