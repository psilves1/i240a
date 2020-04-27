
#include <iostream>

class Delim{
private:
    int delimVal;

public:
    Delim(int delim){
        delimVal = delim;
    }

    Delim(){};

    int getDelimType(){

        char c = (char) delimVal;

        if(c == '(')
            return 1;
        else if (c == ')')
            return -1;
        else if (c == '[')
            return 2;
        else if (c == ']')
            return -2;
        else if (c == '{')
            return 3;
        else if (c == '}')
            return -3;
        else if (c == '<')
            return 4;
        else if (c == '>')
            return -4;
        else{
            return 0;
        }
    }

    char toString(){
        return (char) delimVal;
    }

};

class Stack{
private:
    int nextIndex;
    Delim stk [];

public:

    Stack(){
        nextIndex = 0;

    }

    //positive value means it was pushed successfully
    //negative value means it was pushed unsuccessfully
    int push(Delim c){
        if(nextIndex < 16){
            stk[nextIndex] = c;
            nextIndex++;
            return 1;
        }
        return -1;
    }

    Delim pop(){
        if(nextIndex > 0) {
            Delim d = stk[nextIndex - 1];
            stk[nextIndex - 1] = 0;
            nextIndex--;
            return d;
        }
        //std::cerr << "invalid pop" << std::endl;
        return Delim(0);
    }

    int size(){
        return nextIndex;
    }



};


int go(int argc, char *argv[]){

    Stack* stk = new Stack();

    int counter = 1;

    for(int i = 1; i <= argc - 1; i++){

        int x = *argv[i];

        Delim d =  Delim(x);

        if(d.getDelimType() == 0){
            //std::cout << "-1" << std::endl;
            std::cerr << "invalid delimiter '" << d.toString() << "'" << std::endl;
            return 1;
        }

        if(d.getDelimType() > 0){
            stk->push(d);
            //std::cout << "stage 1" << std::endl;
        }else {

            Delim del = stk->pop();
            //stk->del();

            if (del.getDelimType() !=  0 && (d.getDelimType() + del.getDelimType()) == 0) { //if nullptr, it will short circuit
                //good pop
                //std::cout << "stage 2" << std::endl;
            }
            else{
                std::cerr << "unbalanced at argument " <<  counter << std::endl;
                //std::cout << "stage 3" << std::endl;
                //std::cout << "-1" << std::endl;
                return 1;
            }
        }

        counter++;

    }

    //std::cout << '0' <<std::endl;
    if(stk->size() > 0) {
        std::cerr << "unbalanced at argument " << counter - 1 << std::endl;
        return 1;
    }

    return 0;
}


int main(int argc, char *argv[]){

    return go(argc, argv);
}