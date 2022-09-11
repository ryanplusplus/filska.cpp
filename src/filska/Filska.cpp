#include "filska/Filska.hpp"
#include "filska/Parser.hpp"
#include "filska/Vm.hpp"

using std::string;
using namespace filska;

void filska::Filska::run(string s)
{
  auto program = Parser::parse(s);
  Vm::run(program);
}
