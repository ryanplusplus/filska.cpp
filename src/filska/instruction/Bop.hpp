#ifndef filska_instruction_Bop_hpp
#define filska_instruction_Bop_hpp

#include <cmath>
#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Bop : public filska::Instruction {
   public:
    Bop(std::string op, char result, char op1, char op2)
      : op{op}, result{result}, op1{op1}, op2{op2}
    {
    }

   protected:
    void _execute(State& state, std::istream&, std::ostream&) override
    {
      auto& _result = reg_for_char(result, state);
      auto& _op1 = reg_for_char(op1, state);
      auto& _op2 = reg_for_char(op2, state);

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

      state.reg.pc += 1;
    }

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
    std::string op;
    char result;
    char op1;
    char op2;
  };
}

#endif
