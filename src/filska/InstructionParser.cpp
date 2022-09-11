#include "filska/InstructionParser.hpp"
#include "filska/instruction/all.hpp"

using namespace filska;
using namespace filska::instruction;

std::unique_ptr<Instruction> InstructionParser::parse(std::string s)
{
  if(s == "hlt") {
    return std::make_unique<Hlt>();
  }
  else if(s == "ipt") {
    return std::make_unique<Ipt>();
  }
  else if(s == "prt") {
    return std::make_unique<Prt>();
  }

  throw std::invalid_argument("Unknown instruction");
}
