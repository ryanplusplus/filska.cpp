#include "Vm.hpp"

using namespace filska;

void Vm::run(Program& program, std::istream& input, std::ostream& output)
{
  while(!program.done) {
    auto& sub_program = program.sub_programs[program.current_sub_program];
    auto& pc = sub_program.pc;
    auto instruction = sub_program.instructions[pc].get();
    auto pc_offset = instruction->execute(program, input, output);
    pc = (pc + pc_offset) % sub_program.instructions.size();
  }
}
