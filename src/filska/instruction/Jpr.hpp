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

    ssize_t execute(Program& program, std::istream&, std::ostream&) override
    {
      auto pc = program.sub_programs[program.current_sub_program].pc;
      program.current_sub_program = target;
      return -pc;
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
