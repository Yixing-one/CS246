#ifndef _MASTERMIND_H_
#define _MASTERMIND_H_
#include <random>

struct Mastermind {
    int codeLength;
    int guessLimit;
    char* code;
    // You may add any data members you require
    // as well as any member functions you like.
    // So long as all the methods below are properly
    // implemented.
    Mastermind(int codeLength, int guessLimit);
    ~Mastermind();
    bool playGame();
};

#endif
