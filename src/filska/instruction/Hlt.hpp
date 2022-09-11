#ifndef filska_instruction_Hlt_hpp
#define filska_instruction_Hlt_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Hlt : public filska::Instruction {
   public:
    ssize_t execute(Program& program, std::istream&, std::ostream&) override
    {
      program.done = true;
      return 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<Hlt const*>(&other) != nullptr;
    }
  };
}

#endif
