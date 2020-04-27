#include <memory>
#include <string>
#include <istream>
#include <iostream>

#include <cassert>
#include <cstdlib>

#include "command.hh"
#include "job.hh"

static Command::Cmd stringToCmd(std::string str) {
  if (str == "enter") {
    return Command::Cmd::ENTER;
  }
  else if (str == "leave") {
    return Command::Cmd::LEAVE;
  }
  else if (str == "move") {
    return Command::Cmd::MOVE;
  }
  else {
    std::cerr << "invalid command \"" << str << "\"" << std::endl;
    std::exit(1);
  }
}

static std::string cmdToString(Command::Cmd cmd) {
  switch (cmd) {
  case Command::Cmd::ENTER:
    return "enter";
  case Command::Cmd::LEAVE:
    return "leave";
  case Command::Cmd::MOVE:
    return "move";
  default:
    assert(false); //shut up g++ warning
  }
}

Command::Command(Command::Cmd cmd) : cmd(cmd) { }

std::string Command::toString() const {
  return cmdToString(cmd);
}

EnterCommand::EnterCommand(Command::Cmd cmd, Job job)
  : Command(cmd), job(job)
{
}

std::ostream& operator<<(std::ostream& out, const Command& command) {
  return out << command.toString();
}


  
std::string EnterCommand::toString() const {
  return Command::toString() + " " + job.toString(); 
}


/** Return next command read from in.  Returns nullptr on EOF */
std::unique_ptr<Command> Command::read(std::istream& in) {
  std::string str;
  if (!(in >> str)) {
    return nullptr;
  }
  Command::Cmd cmd = stringToCmd(str);
  if (cmd != Command::Cmd::ENTER) {
    return std::make_unique<Command>(cmd);
  }
  else {
    Job job = *Job::read(in);
    return std::make_unique<EnterCommand>(cmd, job);
  }
}
