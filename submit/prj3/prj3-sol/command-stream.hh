#include <fstream>
#include <memory>
#include <string>

#include "command.hh"

/** Create a stream of commands on a file.  Access using next() */
class CommandStream {
public:
  CommandStream(std::string filePath);
  CommandStream(std::ifstream& in, std::string filePath="");

  /** return next command; nullptr on EOF */
  std::unique_ptr<Command> next();
private:
  std::ifstream in;
  std::string filePath;
};

