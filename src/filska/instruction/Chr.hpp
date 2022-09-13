#ifndef filska_instruction_Chr_hpp
#define filska_instruction_Chr_hpp

#include <cmath>
#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Chr : public filska::Instruction {
   public:
    void execute(State& state, std::istream&, std::ostream& output) override
    {
      output << (char)state.reg.m;
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
