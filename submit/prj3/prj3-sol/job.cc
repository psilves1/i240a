#include <memory>
#include <string>
#include <iostream>

#include <cstdlib>

#include "job.hh"

Job::Job(std::string id, int priority0, int priority1) :
  id(id), priority0(priority0), priority1(priority1) { }


/** Return next job read from in.  Returns nullptr on EOF */
std::unique_ptr<Job> Job::read(std::istream& in) {
  std::string id;
  if (!(in >> id)) return nullptr;
  int priority0, priority1;
  if (!(in >> priority0) || !(in >> priority1)) {
    std::cerr << "unexpected EOF while reading Job " << id << std::endl;
    std::exit(1);
  }
  return std::make_unique<Job>(id, priority0, priority1);
}

std::string Job::toString() const {
  return id + " " + std::to_string(priority0) + " " + std::to_string(priority1);
}

std::ostream& operator<<(std::ostream& out, const Job& job) {
  return out << job.toString();
}
