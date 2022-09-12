#ifndef filska_instruction_Tmy_hpp
#define filska_instruction_Tmy_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Tmy : public filska::Instruction {
   public:
    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.y = state.m;
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
