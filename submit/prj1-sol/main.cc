#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <map>

#include "main.h"

bool wordCountCompare(WordCount a, WordCount b){
  
  if(a.second ==  b.second){
    //    std::cout<< a.first<< "is at "<<  a.second <<  "\n and " << b.first << "is at" << b.second << std::endl;
    //    std::cout <<  "they were equal" << std::endl;
    return (a.first.compare(b.first) < 0);
  }

  //  std::cout<< a.first<< "is at " << a.second <<  "\n and " << b.first << "is at" << b.second << std::endl;
  //std::cout << "they ran the second one" << std::endl;
  //std::cout << a. first <<  " <  " << b.second << "?" << std::endl;
  //  std::cout << a.first << " = " << a.second << " and " << b.first << " = " << b.second << std::endl;
  return a.second > b.second;
}

int main(int argc, char *argv[]){

  //ADD A USAGE MESSAGE
  //if argc < some num -> print usage message
  //return true if first arg is less than second arg                                                                                              
  if(argc < 5){
    std::cerr << "usage: ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE..." << std::endl;
    return 0;
  }


  
  auto args = std::vector<std::string>(&argv[0], &argv[argc]);

  std::string::size_type endIndex;
  const int MAX_N_OUT =  std::stoi(args.at(1), &endIndex);
  if(!(endIndex == args.at(1).length())){
    std::cerr << "Please use a proper integer for MAX_N_OUT" << std::endl;
    return 0;
  }

  const int MIN_WORD_LEN =  std::stoi(args.at(2), &endIndex);
  if(!(endIndex == args.at(2).length())){
    std::cerr << "Please use a proper integer for MIN_WORD_LEN" << std::endl;
    return 0;
  }

  const int MAX_WORD_LEN =  std::stoi(args.at(3), &endIndex);
  if(!(endIndex == args.at(3).length())){
    std::cerr << "Please use a proper integer for MAX_WORD_LEN" << std::endl;
    return 0;
  }

  //checks if min is greater than max
  if(MIN_WORD_LEN > MAX_WORD_LEN){
    std::cout << "MIN_WORD_LEN is greater than MAX_WORD_LEN" << std::endl;
    return 0;
  }

  typedef int Count;
  //map to put the words in
  std::unordered_map<std::string, Count> map;
  
  //TO DO
  //put this in a for loop so that you can read in multiple lines at a time
  for(int i = 4; i < argc; i++){
    std::ifstream in(args.at(i));
    while (in.good()) {
      std::string w;
      in >> w;

    
      //Checks if the word fits within our requirments
      if((int)w.length() > MAX_WORD_LEN)
	continue;
      if((int)w.length() < MIN_WORD_LEN)
	continue;

    
      //checks if w is in our map.
      //If so, increament w counter by 1.
      //If not, add it to the map    
      if(map[w] == 0){
	map[w] = 1;
      }
      else{
	map[w] += 1;
      }

      /*
      //Sort the map
      //    typedef std::pair<std::string, Count> WordCount;
      auto wordCounts =
      std::vector<WordCount>(map.begin(), map.end());
      
      std::sort(wordCounts.begin(), wordCounts.end(),
      wordCountCompare);    
      */
    }
      if (!in.eof()) {
	std::cerr << "Bad file input: No such file or directory exists" << std::endl; //                                                                                              
	return 0;
	//might need to make this a better error message later                                                                                        
      }

    
  }
    //Sort the map                                                                                                                                
    //    typedef std::pair<std::string, Count> WordCount;                                                                                        
    /*
      std::cout << "Before: " << std::endl;
      for(auto i = map.begin(); i != map.end(); i++){
      
      //    if(numOfPrints > MAX_N_OUT)
      //break;
    
      std::cout << i->first << " : " << i->second << std::endl;
      }
    */
  
  auto wordCounts =
    std::vector<WordCount>(map.begin(), map.end());

  
  std::sort(wordCounts.begin(), wordCounts.end(),
	    wordCountCompare);

  //std::cout << "\n\n After: " << std::endl;
  
  int numOfPrints = 0;
  //print out the words with their counts                                                                                                       
  for(auto i = wordCounts.begin(); i != wordCounts.end(); i++){

    numOfPrints++;
    
    if(numOfPrints > MAX_N_OUT)
      break;
    
    std::cout << i->first << " : " << i->second << std::endl;
  }

  
  return 0;
}


