#ifndef filska_instruction_Ipt_hpp
#define filska_instruction_Ipt_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Ipt : public filska::Instruction {
   protected:
    void _execute(State& state, std::istream& input, std::ostream&) override
    {
      float f;
      input >> f;

      if(input) {
        state.reg.m = f;
        state.reg.pc += 1;
      }
      else {
        state.done = true;
      }
    }

    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
