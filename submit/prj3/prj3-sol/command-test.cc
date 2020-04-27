#include <memory>
#include <string>
#include <istream>
#include <iostream>

#include <cstdlib>

#include "command.hh"
#include "command-stream.hh"

/** Test program for command stream */
int
main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cerr << "usage: " << argv[0] << " FILE_PATH" << std::endl;
    std::exit(1);
  }
  
  CommandStream commandIn(argv[1]); //create command stream
  for (std::unique_ptr<Command> commandP = commandIn.next();
       commandP != nullptr;
       commandP = commandIn.next()) {
    std::cout << *commandP << std::endl;
  }
}
