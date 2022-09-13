#ifndef filska_instruction_Rnd_hpp
#define filska_instruction_Rnd_hpp

#include <random>
#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Rnd : public filska::Instruction {
   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      std::default_random_engine re;
      std::uniform_real_distribution<double> unif(0, 1);
      state.reg.m = unif(re);

      state.reg.pc += 1;
    }

    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
