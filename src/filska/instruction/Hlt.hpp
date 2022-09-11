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

   protected:
    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<Hlt const*>(&other) != nullptr;
    }
  };
}

#endif
