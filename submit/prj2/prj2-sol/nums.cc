#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>

#include "arrayseq.hh"
//#include "dlinkseq.hh"

using TestType = int;

int main(int argc, char* argv[]){

    if(argc < 2 || argc > 4){
        std::cout << "usage ./nums [-a] INTS_FILE_PATH" << std::endl;
        return 0;
    }

    const char* dashA = "-a";

    SeqPtr<TestType> ptr;


    if(argc == 3){

        if(strcmp(dashA, (const char*)argv[1]) != 0){
            std::cout << "usage ./nums [-a] INTS_FILE_PATH" << std::endl;
            return 0;
        }
        
        ptr = ArraySeq<TestType>::make();
        Seq<TestType>* seq = ptr.get();

        std::ifstream in(argv[2]);

        if(!in){
            std::cerr << "cannot read \"" << argv[2] << "\"" << '\n' << " No such file or directory" << std::endl;
            return 0;
        }

        int w;
        while(in >> w){
            seq->push(w);
        }

        if(!in.eof()){
            std::cerr << "Error with file \"" << argv[2] << "\"" << std::endl;
            return 0;
        }

        ConstIterPtr<TestType> start = seq->cbegin();

        ConstIterPtr<TestType> end = seq->cend();

        for(int i = 0; i < seq->size(); i++){

            std::cout<< *(*start) << std::endl;
            std::cout<< *(*end) << std::endl;

            ++(*start);
            --(*end);
        }

    }

    if(argc == 2){
        
        std::ifstream in(argv[1]);

        if(!in){
            std::cerr << "cannot read \"" << argv[1] << "\"" << '\n' << " No such file or directory" << std::endl;
            return 0;
        }

        //TODO Change this to the DLinkSeq implementation once you're finished
        ptr = ArraySeq<TestType>::make();
        Seq<TestType>* seq = ptr.get();

        int w;
        while(in >> w){
            seq->push(w);
        }

        if(!in.eof()){
            std::cerr << "Error with file \"" << argv[1] << "\"" << std::endl;
            return 0;
        }

        ConstIterPtr<TestType> start = seq->cbegin();

        ConstIterPtr<TestType> end = seq->cend();

        for(int i = 0; i < seq->size(); i++){

            std::cout<< *(*start) << std::endl;
            std::cout<< *(*end) << std::endl;

            ++(*start);
            --(*end);
        }

    }
    

    return 0;
}