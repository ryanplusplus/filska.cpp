#ifndef filska_Program_hpp
#define filska_Program_hpp

#include <map>
#include <string>
#include "filska/SubProgram.hpp"

namespace filska {
  struct Program {
    double x{};
    double y{};
    double z{};

    bool done{};

    std::map<std::string, SubProgram> sub_programs{};

    std::string current_sub_program{};

    bool operator==(const Program& other) const = default;
  };
}
#endif
