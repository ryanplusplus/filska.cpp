#ifndef filska_instruction_Tmz_hpp
#define filska_instruction_Tmz_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Tmz : public filska::Instruction {
   public:
    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.reg.z = state.reg.m;
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
