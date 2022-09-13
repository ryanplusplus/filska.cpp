#ifndef filska_instruction_Cmp_hpp
#define filska_instruction_Cmp_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Cmp : public filska::Instruction {
   public:
    Cmp(char reg)
      : reg{reg}
    {
    }

   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      update_flags(reg_for_char(reg, state), state);
      state.reg.pc += 1;
    }

    bool equal_to(const Instruction& other) const override
    {
      if(auto _other = dynamic_cast<decltype(this)>(&other)) {
        return this->reg == _other->reg;
      }
      return false;
    }

   private:
    char reg;
  };
}

#endif
