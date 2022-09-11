#include <sstream>
#include <iostream>
#include <algorithm>
#include "filska/Parser.hpp"
#include "filska/InstructionParser.hpp"

using namespace filska;

enum class State {
  idle,
  name,
  instructions
};

Program Parser::parse(std::string s)
{
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);

  auto program = Program{};
  program.current_sub_program = "main";
  auto current_name = std::string{};
  auto state = State::idle;

  std::istringstream source_stream{s};
  std::string line;

  while(std::getline(source_stream, line)) {
    if(line.empty()) {
      continue;
    }

    std::istringstream line_stream{line};
    std::string chunk;

    while(std::getline(line_stream, chunk, ' ')) {
      if(chunk.empty()) {
        continue;
      }

      if(chunk.starts_with("\"")) {
        break;
      }

      switch(state) {
        case State::idle:
          if(chunk == "{") {
            state = State::name;
          }
          break;

        case State::name:
          program.sub_programs[chunk] = SubProgram{};
          current_name = chunk;
          state = State::instructions;
          break;

        case State::instructions:
          if(chunk == "}") {
            state = State::idle;
          }
          else {
            auto instruction = InstructionParser::parse(chunk);
            program.sub_programs[current_name].instructions.push_back(std::move(instruction));
          }
          break;
      }
    }
  }

  return program;
}
