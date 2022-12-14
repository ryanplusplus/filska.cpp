#ifndef filska_instruction_Hlt_hpp
#define filska_instruction_Hlt_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Hlt : public filska::Instruction {
   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      state.done = true;
    }

    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
