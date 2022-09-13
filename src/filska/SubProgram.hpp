#ifndef SubProgram_hpp
#define SubProgram_hpp

#include <vector>
#include <memory>
#include "Instruction.hpp"

namespace filska {
  struct SubProgram {
    double m{};

    struct {
      bool l{};
      bool g{};
      bool e{};
      bool z{};
    } flag{};

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
        (this->flag.l == other.flag.l) &&
        (this->flag.g == other.flag.g) &&
        (this->flag.e == other.flag.e) &&
        (this->flag.z == other.flag.z) &&
        (this->pc == other.pc);
    }
  };
}

#endif
