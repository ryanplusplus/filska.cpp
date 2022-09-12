#ifndef filska_instruction_Tym_hpp
#define filska_instruction_Tym_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Tym : public filska::Instruction {
   public:
    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.m = state.y;
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
