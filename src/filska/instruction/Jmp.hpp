#ifndef filska_instruction_Jmp_hpp
#define filska_instruction_Jmp_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Jmp : public filska::Instruction {
   public:
    Jmp(std::string target)
      : target{target}
    {
    }

    ssize_t execute(Program& program, std::istream&, std::ostream&) override
    {
      program.current_sub_program = target;
      return 1;
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
