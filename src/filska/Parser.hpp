#ifndef filska_Parser_hpp
#define filska_Parser_hpp

#include <string>
#include "filska/Program.hpp"

namespace filska {
class Parser {
 public:
  static Program parse(std::string);
};
}

#endif
