#ifndef filska_Program_hpp
#define filska_Program_hpp

#include <map>
#include <string>
#include "filska/SubProgram.hpp"

namespace filska {
  struct Program {
    float x{};
    float y{};
    float z{};

    bool done{};

    std::map<std::string, SubProgram> sub_programs{};

    SubProgram* current_sub_program{};
  };
}
#endif
