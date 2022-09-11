#ifndef SubProgram_hpp
#define SubProgram_hpp

#include <vector>
#include <memory>
#include "Instruction.hpp"

namespace filska {
  struct SubProgram {
    float m{};

    bool z{};
    bool e{};
    bool g{};
    bool l{};

    size_t pc{};

    std::vector<std::unique_ptr<Instruction>> instructions{};

    bool operator==(const SubProgram& other) const
    {
      if(this->instructions.size() != other.instructions.size()) {
        return false;
      }

      for(size_t i = 0; i < this->instructions.size(); i++) {
        if(*this->instructions[i].get() != *other.instructions[i].get()) {
          return false;
        }
      }

      return true &&
        (this->m == other.m) &&
        (this->z == other.z) &&
        (this->e == other.e) &&
        (this->g == other.g) &&
        (this->l == other.l) &&
        (this->pc == other.pc);
    }
  };
}

#endif
