#ifndef filska_Instruction_hpp
#define filska_Instruction_hpp

#include <typeinfo>
#include <iostream>

namespace filska {
  struct Program;

  class Instruction {
   public:
    struct State {
      struct {
        double& x;
        double& y;
        double& z;

        double& m;

        size_t& pc;
      } reg;

      struct {
        bool& l;
        bool& g;
        bool& e;
        bool& z;
      } flag;

      bool& done;

      std::string& current_sub_program;
    };

   public:
    virtual ~Instruction(){};
    virtual void execute(State& state, std::istream& input, std::ostream& output)
    {
      _execute(state, input, output);
      state.flag.z = (state.reg.m == 0);
    };

    friend bool operator==(const Instruction& lhs, const Instruction& rhs)
    {
      return lhs.equal_to(rhs);
    }

   protected:
    virtual bool equal_to(const Instruction& other) const = 0;
    virtual void _execute(State& state, std::istream& input, std::ostream& output) = 0;

    double& reg_for_char(char which, State& state)
    {
      switch(which) {
        case 'x':
          return state.reg.x;

        case 'y':
          return state.reg.y;

        case 'z':
          return state.reg.z;

        default:
        case 'm':
          return state.reg.m;
      }
    }

    bool& flag_for_char(char which, State& state)
    {
      switch(which) {
        case 'l':
          return state.flag.l;

        case 'g':
          return state.flag.g;

        case 'e':
          return state.flag.e;

        default:
        case 'z':
          return state.flag.z;
      }
    }

    void update_flags(double value, State& state)
    {
      state.flag.l = (state.reg.m < value);
      state.flag.g = (state.reg.m > value);
      state.flag.e = (state.reg.m == value);
    }
  };
}

#endif
