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

    ssize_t execute(Program& program, std::istream&, std::ostream&) override
    {
      auto& sub_program = program.sub_programs[program.current_sub_program];

      auto& _a = value(a, program, sub_program);
      auto& _b = value(b, program, sub_program);

      auto temp = _a;
      _a = _b;
      _b = temp;

      return 1;
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
    float& value(char which, Program& program, SubProgram& sub_program)
    {
      switch(which) {
        case 'x':
          return program.x;

        case 'y':
          return program.y;

        case 'z':
          return program.z;

        default:
        case 'm':
          return sub_program.m;
      }
    }

    char a;
    char b;
  };
}

#endif
