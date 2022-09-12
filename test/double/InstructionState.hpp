#ifndef double_InstructionState_hpp
#define double_InstructionState_hpp

#include "filska/Instruction.hpp"

struct InstructionState {
  float x{};
  float y{};
  float z{};

  float m{};

  size_t pc{};

  bool done{};

  std::string current_sub_program{};

  filska::Instruction::State state{
    x,
    y,
    z,
    m,
    pc,
    done,
    current_sub_program,
  };
};

#endif
