#ifndef filska_instruction_Tst_hpp
#define filska_instruction_Tst_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Tst : public filska::Instruction {
   public:
    Tst(char flag, ssize_t offset)
      : flag{flag}, offset{offset}
    {
    }

   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      if(flag_for_char(flag, state)) {
        state.reg.pc += offset;
      }
      else {
        state.reg.pc += 1;
      }
    }

    bool equal_to(const Instruction& other) const override
    {
      if(auto _other = dynamic_cast<decltype(this)>(&other)) {
        return (this->flag == _other->flag) && (this->offset == _other->offset);
      }
      return false;
    }

   private:
    char flag;
    ssize_t offset;
  };
}

#endif
