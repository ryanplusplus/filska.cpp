#ifndef double_InstructionState_hpp
#define double_InstructionState_hpp

#include "filska/Instruction.hpp"

struct InstructionState {
  struct {
    double x{};
    double y{};
    double z{};

    double m{};

    size_t pc{};
  } reg{};

  struct {
    bool l{};
    bool g{};
    bool e{};
    bool z{};
  } flag{};

  bool done{};

  std::string current_sub_program{};

  filska::Instruction::State state{
    {
      reg.x,
      reg.y,
      reg.z,
      reg.m,
      reg.pc,
    },
    {
      flag.l,
      flag.g,
      flag.e,
      flag.z,
    },
    done,
    current_sub_program,
  };
};

#endif
