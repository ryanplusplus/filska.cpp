#ifndef filska_instruction_Set_hpp
#define filska_instruction_Set_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Set : public filska::Instruction {
   public:
    Set(float v)
      : v{v}
    {
    }

    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.m = v;
      state.pc += 1;
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
