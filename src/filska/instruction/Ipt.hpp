#ifndef filska_instruction_Ipt_hpp
#define filska_instruction_Ipt_hpp

#include <iostream>
#include "filska/Program.hpp"

namespace filska::instruction {
  class Ipt : public filska::Instruction {
   public:
    ssize_t execute(Program& program, std::istream& input, std::ostream&) override
    {
      float f;
      input >> f;

      if(input) {
        program.sub_programs[program.current_sub_program].m = f;
      }
      else {
        program.done = true;
      }

      return 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<Ipt const*>(&other) != nullptr;
    }
  };
}

#endif
