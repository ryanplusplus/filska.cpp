#ifndef filska_instruction_Tmx_hpp
#define filska_instruction_Tmx_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Tmx : public filska::Instruction {
   public:
    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.reg.x = state.reg.m;
      state.reg.pc += 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
