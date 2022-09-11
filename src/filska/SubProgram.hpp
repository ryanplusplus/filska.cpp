#ifndef SubProgram_hpp
#define SubProgram_hpp

#include <vector>
#include "Instruction.hpp"

namespace filska {
  struct SubProgram {
    float m{};

    bool z{};
    bool e{};
    bool g{};
    bool l{};

    size_t pc{};

    std::vector<Instruction> instructions{};
  };
}

#endif
