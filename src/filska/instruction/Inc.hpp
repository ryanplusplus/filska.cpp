#ifndef filska_instruction_Inc_hpp
#define filska_instruction_Inc_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Inc : public filska::Instruction {
   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      state.reg.m += 1;
      state.reg.pc += 1;
    }

    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
