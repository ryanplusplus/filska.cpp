#ifndef filska_instruction_Gto_hpp
#define filska_instruction_Gto_hpp

#include "filska/Instruction.hpp"

namespace filska::instruction {
  class Gto : public filska::Instruction {
   public:
    Gto(ssize_t offset)
      : offset{offset}
    {
    }

    void execute(State& state, std::istream&, std::ostream&) override
    {
      state.reg.pc += offset;
    }

   protected:
    bool equal_to(const Instruction& other) const override
    {
      if(auto _other = dynamic_cast<decltype(this)>(&other)) {
        return this->offset == _other->offset;
      }
      return false;
    }

   private:
    ssize_t offset;
  };
}

#endif
