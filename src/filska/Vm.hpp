#ifndef filska_Vm_hpp
#define filska_Vm_hpp

#include <iostream>
#include "filska/Program.hpp"

namespace filska {
  class Vm {
   public:
    static void run(Program& program, std::istream& input, std::ostream& output);
  };
}

#endif
