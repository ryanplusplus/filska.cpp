#ifndef filska_instruction_Prt_hpp
#define filska_instruction_Prt_hpp

#include <cmath>
#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Prt : public filska::Instruction {
   protected:
    void _execute(State& state, std::istream&, std::ostream& output) override
    {
      if(std::floor(state.reg.m) == state.reg.m) {
        output << static_cast<int>(state.reg.m);
      }
      else {
        output << state.reg.m;
      }

      state.reg.pc += 1;
    }

    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
