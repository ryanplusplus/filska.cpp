#ifndef filska_instruction_Swp_hpp
#define filska_instruction_Swp_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Swp : public filska::Instruction {
   public:
    Swp(char a, char b)
      : a{a}, b{b}
    {
    }

    void execute(State& state, std::istream&, std::ostream&) override
    {
      auto& _a = value_for_char(a, state);
      auto& _b = value_for_char(b, state);

      auto temp = _a;
      _a = _b;
      _b = temp;

      state.pc += 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      if(auto _other = dynamic_cast<decltype(this)>(&other)) {
        return (this->a == _other->a) && (this->b == _other->b);
      }
      return false;
    }

   private:
    char a;
    char b;
  };
}

#endif
