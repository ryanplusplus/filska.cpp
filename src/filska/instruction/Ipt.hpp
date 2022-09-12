#ifndef filska_instruction_Ipt_hpp
#define filska_instruction_Ipt_hpp

#include <iostream>
#include "filska/Program.hpp"

namespace filska::instruction {
  class Ipt : public filska::Instruction {
   public:
    void execute(State& state, std::istream& input, std::ostream&) override
    {
      float f;
      input >> f;

      if(input) {
        state.m = f;
        state.pc += 1;
      }
      else {
        state.done = true;
      }
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
