#ifndef filska_instruction_Hlt_hpp
#define filska_instruction_Hlt_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Hlt : public filska::Instruction {
   public:
    void execute(Program& program) override
    {
      program.done = true;
    }

    bool operator==(const Hlt&) const
    {
      return true;
    }
  };
}

#endif
