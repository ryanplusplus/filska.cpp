#ifndef filska_Instruction_hpp
#define filska_Instruction_hpp

namespace filska {
  class Program;

  class Instruction {
   public:
    virtual ~Instruction(){};
    virtual void execute(filska::Program& program) = 0;
  };
}

#endif
