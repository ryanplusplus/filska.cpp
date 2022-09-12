#ifndef filska_instruction_Jpr_hpp
#define filska_instruction_Jpr_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Jpr : public filska::Instruction {
   public:
    Jpr(std::string target)
      : target{target}
    {
    }

    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.current_sub_program = target;
      state.pc = 0;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      if(auto _other = dynamic_cast<decltype(this)>(&other)) {
        return this->target == _other->target;
      }
      return false;
    }

   private:
    std::string target;
  };
}

#endif
