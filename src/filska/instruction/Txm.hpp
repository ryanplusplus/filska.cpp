#ifndef filska_instruction_Txm_hpp
#define filska_instruction_Txm_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Txm : public filska::Instruction {
   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      state.reg.m = state.reg.x;
      state.reg.pc += 1;
    }

    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
