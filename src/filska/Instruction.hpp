#ifndef filska_Instruction_hpp
#define filska_Instruction_hpp

#include <typeinfo>
#include <iostream>

namespace filska {
  struct Program;

  class Instruction {
   public:
    struct State {
      float& x;
      float& y;
      float& z;

      float& m;

      size_t& pc;

      bool& done;

      std::string& current_sub_program;
    };

   public:
    virtual ~Instruction(){};
    virtual void execute(State& state, std::istream& input, std::ostream& output) = 0;

    friend bool operator==(const Instruction& lhs, const Instruction& rhs)
    {
      return lhs.equal_to(rhs);
    }

   protected:
    virtual bool equal_to(const Instruction& other) const = 0;

    float& value_for_char(char which, State& state)
    {
      switch(which) {
        case 'x':
          return state.x;

        case 'y':
          return state.y;

        case 'z':
          return state.z;

        default:
        case 'm':
          return state.m;
      }
    }
  };
}

#endif
