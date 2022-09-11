#include "filska/InstructionParser.hpp"
#include "filska/instruction/Ipt.hpp"

using namespace filska;
using namespace filska::instruction;

std::unique_ptr<Instruction> InstructionParser::parse(std::string)
{
  return std::make_unique<Ipt>();
}
