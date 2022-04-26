#include "mastermind.h"
#include "password.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

bool Mastermind::playGame() {
    int time1 = 1;
    char inword[codeLength];
    while(time1 <= guessLimit) {
      if (time1 == 1) {
          cout << "Welcome to Mastermind! Please enter your first guess:" << endl;
      } else {
          cout << "Enter guess:" << endl;
      }
      
      for(int i = 0; i < codeLength; i++) {
           cin >> inword[i];
      }
      
      int black = 0;
      int white = 0;
      int start = 0;
         while (start < codeLength) {
             char c1 = inword[start];
             char c2;
             if( 'A' < c1 < 'Z') {
                 c2 = c1 - 'A' + 'a';
             }
             if( 'a' < c1 < 'z') {
                 c2 = c1 - 'a' + 'A';
             }
             
            if((code[start] == c1) ||  (code[start] == c2)) {
                black += 1;
            } else {
                bool notfound = true;
                for(int i=0; i < start; i++) {
                    if(inword[start] == inword[i]) {
                        notfound = false;
                    }
                }
                if(notfound) {
                    for(int i=0; i < codeLength; i++) {
                         if((code[i] == c1) ||  (code[i] == c2)) {
                             if((inword[i] != c1) && (inword[i] != c2)){
                                white += 1;
                                break;
                             }
                        }   
                    }
                }
            }
            start++;
         }
        
    	   cout << black <<"b,";
            cout << white <<"w"<< endl;
            
            if(black == codeLength) {
              cout << "You won in ";
              cout << time1;
              cout << " guesses!" << endl;
              cout << "Would you like to play again? (Y/N): " << endl;
              char input;
              cin >> input;
              if(input == 'Y') {
                    return true;
               }
                return false;
                break;
            }
        
            if(time1 != guessLimit) {
              int left = guessLimit - time1;
              cout << left;
              cout << " guesses left. "; 
            }
            
    if(time1 == guessLimit) { 
         if(black != codeLength) {
                 cout << "You lost! The password was: ";
                 string str(code);
                 cout << str << endl;
         }
          cout << "Would you like to play again? (Y/N): " << endl;
          char input;
          cin >> input;
          if(input == 'Y') {
                return true;
           }
                return false;
                 break;
    }
      time1++;
    }
    return false;
}

Mastermind:: Mastermind(int codeLength, int guessLimit){
    this->codeLength = codeLength;
    this->guessLimit = guessLimit;
    this->code = new char[codeLength];
}

 Mastermind::  ~Mastermind() {
     delete code;
 }

