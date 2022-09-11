#include <fstream>
#include <sstream>
#include "filska/Filska.hpp"

int main(int, char* argv[])
{
  std::ifstream source_file(argv[1]);
  std::stringstream source_buffer;
  source_buffer << source_file.rdbuf();

  filska::Filska::run(source_buffer.str());
}
