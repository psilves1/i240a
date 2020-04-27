#include <cctype>
#include <iostream>
#include <string.h>

#include "digit-sum.hh"

int
digitSum(const char* str) {
    int acc = 0;
    int counter = 0;
    bool lastCharWasDigit = false;
    bool lastCharWasPlus = false;

    for (const char *p = &str[0]; counter < (int) strlen(str); ++p) {
        counter++;
        int c = *p;
        //std::cout << *p << std::endl;
        if (isdigit(c)) {
            if(lastCharWasDigit){
                break;
            }
            lastCharWasDigit = true;
            lastCharWasPlus = false;
            acc += *p - '0';

        } else if (*p == ' '){
            continue;
        }
        else if(*p == '+') {
            if (lastCharWasPlus == true)
                break;
            lastCharWasPlus = true;
            lastCharWasDigit = false;
            continue;
        }else{
            break;
        }
    }

    return acc;
}