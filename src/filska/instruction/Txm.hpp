#ifndef filska_instruction_Txm_hpp
#define filska_instruction_Txm_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Txm : public filska::Instruction {
   public:
    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.m = state.x;
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
