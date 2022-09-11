#include "filska/InstructionParser.hpp"
#include "filska/instruction/Ipt.hpp"
#include "filska/instruction/Hlt.hpp"

using namespace filska;
using namespace filska::instruction;

std::unique_ptr<Instruction> InstructionParser::parse(std::string s)
{
  if(s == "ipt") {
    return std::make_unique<Ipt>();
  }
  else if(s == "hlt") {
    return std::make_unique<Hlt>();
  }

  throw std::invalid_argument("Unknown instruction");
}
