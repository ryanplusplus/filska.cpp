#ifndef filska_instruction_Bop_hpp
#define filska_instruction_Bop_hpp

#include <cmath>
#include "filska/Program.hpp"

namespace filska::instruction {
  class Bop : public filska::Instruction {
   public:
    Bop(std::string op, char result, char op1, char op2)
      : op{op}, result{result}, op1{op1}, op2{op2}
    {
    }

    ssize_t execute(Program& program, std::istream&, std::ostream&) override
    {
      auto& sub_program = program.sub_programs[program.current_sub_program];

      auto& _result = value(result, program, sub_program);
      auto& _op1 = value(op1, program, sub_program);
      auto& _op2 = value(op2, program, sub_program);

      if(op == "add") {
        _result = _op1 + _op2;
      }
      else if(op == "sub") {
        _result = _op1 - _op2;
      }
      else if(op == "mul") {
        _result = _op1 * _op2;
      }
      else if(op == "div") {
        _result = _op1 / _op2;
      }
      else if(op == "mod") {
        _result = static_cast<long>(_op1) % static_cast<long>(_op2);
      }
      else if(op == "pow") {
        _result = static_cast<float>(pow(_op1, _op2));
      }

      return 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      if(auto _other = dynamic_cast<decltype(this)>(&other)) {
        return true &&
          (this->op == _other->op) &&
          (this->result == _other->result) &&
          (this->op1 == _other->op1) &&
          (this->op2 == _other->op2);
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

    std::string op;
    char result;
    char op1;
    char op2;
  };
}

#endif
