#ifndef filska_instruction_Ipt_hpp
#define filska_instruction_Ipt_hpp

#include <iostream>
#include "filska/Program.hpp"

namespace filska::instruction {
  class Ipt : public filska::Instruction {
   public:
    void execute(Program& program) override
    {
      float input;
      std::cin >> input;

      if(std::cin) {
        program.sub_programs[program.current_sub_program].m = input;
      }
      else {
        program.done = true;
      }
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<Ipt const*>(&other) != nullptr;
    }
  };
}

#endif
