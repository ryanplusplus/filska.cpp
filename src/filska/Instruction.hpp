#ifndef filska_Instruction_hpp
#define filska_Instruction_hpp

#include <typeinfo>

namespace filska {
  struct Program;

  class Instruction {
   public:
    virtual ~Instruction(){};
    virtual void execute(filska::Program& program) = 0;

    friend bool operator==(const Instruction& lhs, const Instruction& rhs)
    {
      return lhs.equal_to(rhs);
    }

   protected:
    virtual bool equal_to(const Instruction& other) const = 0;
  };
}

#endif
