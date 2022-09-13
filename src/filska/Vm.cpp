#include "Vm.hpp"

using namespace filska;

void Vm::run(Program& program, std::istream& input, std::ostream& output)
{
  while(!program.done) {
    auto& sub_program = program.sub_programs[program.current_sub_program];
    auto& pc = sub_program.pc;
    auto state = Instruction::State{
      {
        program.x,
        program.y,
        program.z,
        sub_program.m,
        sub_program.pc,
      },
      {
        sub_program.flag.l,
        sub_program.flag.g,
        sub_program.flag.e,
        sub_program.flag.z,
      },
      program.done,
      program.current_sub_program,
    };

    auto instruction = sub_program.instructions[pc].get();
    instruction->execute(state, input, output);
    pc %= sub_program.instructions.size();
  }
}
