#ifndef filska_instruction_Set_hpp
#define filska_instruction_Set_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Set : public filska::Instruction {
   public:
    Set(float v)
      : v{v}
    {
    }

    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.reg.m = v;
      state.reg.pc += 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      if(auto _other = dynamic_cast<decltype(this)>(&other)) {
        return this->v == _other->v;
      }
      return false;
    }

   private:
    float v;
  };
}

#endif
