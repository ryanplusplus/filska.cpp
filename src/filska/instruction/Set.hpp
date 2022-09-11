#ifndef filska_instruction_Set_hpp
#define filska_instruction_Set_hpp

#include "filska/Program.hpp"

namespace filska::instruction {
  class Set : public filska::Instruction {
   public:
    Set(float v)
      : v{v}
    {
    }

    ssize_t execute(Program& program, std::istream&, std::ostream&) override
    {
      program.sub_programs[program.current_sub_program].m = v;
      return 1;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      if(auto _other = dynamic_cast<decltype(this)>(&other)) {
        return this->v == _other->v;
      }
      return false;
    }

   private:
    float v;
  };
}

#endif
