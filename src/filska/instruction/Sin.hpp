#ifndef filska_instruction_Sin_hpp
#define filska_instruction_Sin_hpp

#include <cmath>
#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Sin : public filska::Instruction {
   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      state.reg.m = std::sin(state.reg.m);
      state.reg.pc += 1;
    }

    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
