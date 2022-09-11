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
        program.current_sub_program->m = input;
      }
      else {
        program.done = true;
      }
    }

    bool operator==(const Ipt&) const
    {
      return true;
    }
  };
}

#endif
