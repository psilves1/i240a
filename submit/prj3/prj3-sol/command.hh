#ifndef COMMAND_HH_
#define COMMAND_HH_

#include <memory>
#include <string>
#include <iostream>

#include "job.hh"

class Command {
public:
  enum Cmd {
    ENTER, /** enter job into q0 */
    MOVE,  /** mv job from q0 to q1 */
    LEAVE, /** rm "highest" priority job from q1 */
  };
  const Cmd cmd;

  Command(Cmd cmd);
  virtual std::string toString() const;

  /** Return next command read from in.  Returns nullptr on EOF */
  static std::unique_ptr<Command> read(std::istream& in);
  
  friend std::ostream& operator<<(std::ostream& out, const Command& cmd);
};

class EnterCommand : public Command {
public:
  const Job job;

  EnterCommand(Cmd cmd, Job job);
  virtual std::string toString() const;
  friend std::ostream& operator<<(std::ostream& out, const EnterCommand& cmd);
};

#endif //ifndef COMMAND_HH_
