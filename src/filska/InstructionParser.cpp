#include "filska/InstructionParser.hpp"
#include "filska/instruction/all.hpp"

using namespace filska;
using namespace filska::instruction;

std::unique_ptr<Instruction> InstructionParser::parse(std::string s)
{
  if(s.starts_with("acs")) {
    return std::make_unique<Acs>();
  }
  else if(s.starts_with("add") ||
    s.starts_with("sub") ||
    s.starts_with("mul") ||
    s.starts_with("div") ||
    s.starts_with("mod") ||
    s.starts_with("pow")) {
    return std::make_unique<Bop>(s.substr(0, 3), s[4], s[6], s[7]);
  }
  if(s.starts_with("asn")) {
    return std::make_unique<Asn>();
  }
  if(s.starts_with("atn")) {
    return std::make_unique<Atn>();
  }
  else if(s.starts_with("cel")) {
    return std::make_unique<Cel>();
  }
  else if(s.starts_with("chr")) {
    return std::make_unique<Chr>();
  }
  else if(s.starts_with("cmp")) {
    return std::make_unique<Cmp>(s[4]);
  }
  else if(s.starts_with("cos")) {
    return std::make_unique<Cos>();
  }
  else if(s.starts_with("dec")) {
    return std::make_unique<Dec>();
  }
  else if(s.starts_with("exp")) {
    return std::make_unique<Exp>();
  }
  else if(s.starts_with("flr")) {
    return std::make_unique<Flr>();
  }
  else if(s.starts_with("gto")) {
    return std::make_unique<Gto>(std::stol(s.substr(4)));
  }
  else if(s == "hlt") {
    return std::make_unique<Hlt>();
  }
  else if(s == "inc") {
    return std::make_unique<Inc>();
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
  else if(s == "log") {
    return std::make_unique<Log>();
  }
  else if(s == "neg") {
    return std::make_unique<Neg>();
  }
  else if(s == "prt") {
    return std::make_unique<Prt>();
  }
  else if(s == "rnd") {
    return std::make_unique<Rnd>();
  }
  else if(s.starts_with("set")) {
    return std::make_unique<Set>(std::stof(s.substr(4)));
  }
  else if(s.starts_with("sin")) {
    return std::make_unique<Sin>();
  }
  else if(s == "sqr") {
    return std::make_unique<Sqr>();
  }
  else if(s.starts_with("swp")) {
    return std::make_unique<Swp>(s[4], s[5]);
  }
  else if(s.starts_with("tan")) {
    return std::make_unique<Tan>();
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
