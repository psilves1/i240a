#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]){

  //ADD A USAGE MESSAGE

  auto args = std::vector<std::string>(&argv[0], &argv[argc]);

  std::string::size_type endIndex;
  const int MAX_N_OUT =  std::stoi(args.at(1), &endIndex);
  if(!(endIndex == args.at(1).length())){
    std::cout << "Please use a proper integer for MAX_N_OUT" << std::endl;
  }

  const int MIN_WORD_LEN =  std::stoi(args.at(2), &endIndex);
  if(!(endIndex == args.at(2).length())){
    std::cout << "Please use a proper integer for MIN_WORD_LEN" << std::endl;
  }

  const int MAX_WORD_LEN =  std::stoi(args.at(3), &endIndex);
  if(!(endIndex == args.at(3).length())){
    std::cout << "Please use a proper integer for MAX_WORD_LEN" << std::endl;
  }


  std::ifstream in(fileName);
  while (in.good()) {
    std::string w;
    in >> w;
    std::cout << w << std::endl;
  }
  if (!in.eof()) {
    cout << "An error occured" << endl;
    return 0;
    //might need to make this a better error message later
  }

  
  return 0;
}
