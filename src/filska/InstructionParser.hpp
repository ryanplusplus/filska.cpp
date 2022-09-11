#ifndef filska_InstructionParser_hpp
#define filska_InstructionParser_hpp

#include <string>
#include <memory>
#include "filska/Instruction.hpp"

namespace filska {
  class InstructionParser {
   public:
    static std::unique_ptr<Instruction> parse(std::string);
  };
}

#endif
