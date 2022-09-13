#ifndef filska_instruction_Acs_hpp
#define filska_instruction_Acs_hpp

#include <cmath>
#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Acs : public filska::Instruction {
   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      state.reg.m = std::acos(state.reg.m);
      state.reg.pc += 1;
    }

    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
