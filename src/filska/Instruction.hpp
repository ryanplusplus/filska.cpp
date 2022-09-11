#ifndef filska_Instruction_hpp
#define filska_Instruction_hpp

#include <typeinfo>
#include <iostream>

namespace filska {
  struct Program;

  class Instruction {
   public:
    virtual ~Instruction(){};
    virtual ssize_t execute(filska::Program& program, std::istream& input, std::ostream& output) = 0;

    friend bool operator==(const Instruction& lhs, const Instruction& rhs)
    {
      return lhs.equal_to(rhs);
    }

   protected:
    virtual bool equal_to(const Instruction& other) const = 0;
  };
}

#endif
