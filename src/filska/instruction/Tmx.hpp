#ifndef filska_instruction_Tmx_hpp
#define filska_instruction_Tmx_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Tmx : public filska::Instruction {
   public:
    ssize_t execute(Program& program, std::istream&, std::ostream&) override
    {
      auto& sub_program = program.sub_programs[program.current_sub_program];
      program.x = sub_program.m;
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
