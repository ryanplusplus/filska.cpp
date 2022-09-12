#ifndef filska_instruction_Prt_hpp
#define filska_instruction_Prt_hpp

#include <cmath>
#include <iostream>
#include "filska/Program.hpp"

namespace filska::instruction {
  class Prt : public filska::Instruction {
   public:
    void execute(State& state, std::istream&, std::ostream& output) override
    {
      if(std::floor(state.m) == state.m) {
        output << static_cast<int>(state.m);
      }
      else {
        output << state.m;
      }

      state.pc += 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
