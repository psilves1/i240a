#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include <cerrno>
#include <cstring>
#include <cstdlib>

#include "command-stream.hh"
#include "command.hh"


CommandStream::CommandStream(std::string filePath) : filePath(filePath)
{
  in.open(filePath);
  if (!in) {
    std::cerr << "cannot read " << filePath <<  ": " << std::strerror(errno);
    std::exit(1);
  }
}

/** return next command; nullptr on EOF */
std::unique_ptr<Command> CommandStream::next() {
  std::unique_ptr<Command> cmd = Command::read(in);
  if (!cmd) in.close(); //EOF
  return cmd;
}


