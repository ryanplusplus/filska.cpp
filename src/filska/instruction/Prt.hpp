#ifndef filska_instruction_Prt_hpp
#define filska_instruction_Prt_hpp

#include <cmath>
#include <iostream>
#include "filska/Program.hpp"

namespace filska::instruction {
  class Prt : public filska::Instruction {
   public:
    ssize_t execute(Program& program, std::istream&, std::ostream& output) override
    {
      auto m = program.sub_programs[program.current_sub_program].m;

      if(std::floor(m) == m) {
        output << static_cast<int>(m);
      }
      else {
        output << m;
      }

      return 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      return dynamic_cast<decltype(this)>(&other) != nullptr;
    }
  };
}

#endif
