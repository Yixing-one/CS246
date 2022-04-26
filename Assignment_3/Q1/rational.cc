#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "rational.h"

using namespace std;

 Rational::Rational(int num,int den)
    {
        this->num = num;
        this->den = den;
    }
    
 void Rational::simplify() {
     bool negative = false;
     if(((den > 0) && (num >= 0)) || ((den < 0) && (num < 0))) {
         negative = false;
     } else {
         negative = true;
     }
     if(den < 0) {
         den = den * -1;
     }
     if(num < 0) {
         num *=  -1;
     }
     
     int factor = 1;
     int m = num;
     if (num > den) {
         m = den;
     } else {
         m = num;
     }
    
    if(m > 0) {
    for(int i = 1; i <= m; i++) {
        if((num % i == 0) && (den % i == 0)) {
          factor =  i; 
        }
    }
    }
    
    if(factor != 1) {
        num = num/factor;
        den = den/factor;
    }
  
    if (negative) {
             num *= -1;
        }
 }
 
 Rational Rational::operator+(const Rational &rhs) const {
    Rational result(*this);
    int a = num;
    int b = den;
    int c = rhs.getNumerator();
    int d = rhs.getDenominator();
    result.num =  a * d + b * c;
    result.den = b * d;
    result.simplify();
    return result;
 }
 
 Rational Rational::operator-(const Rational &rhs) const {
    Rational result(*this);
    int a = num;
    int b = den;
    int c = rhs.getNumerator();
    int d = rhs.getDenominator();
    result.num = a * d - b * c;
    result.den = b * d;
    result.simplify();
    return result;
 }
 
 Rational Rational::operator*(const Rational &rhs) const {
    Rational result(*this);
    int a = num;
    int b = den;
    int c = rhs.getNumerator();
    int d = rhs.getDenominator();
    result.num = a * c;
    result.den = b * d;
    result.simplify();
    return result;
 }
 
 
 Rational Rational::operator/(const Rational &rhs) const {
    Rational result(*this);
    int a = num;
    int b = den;
    int c = rhs.getNumerator();
    int d = rhs.getDenominator();
    result.num = a * d;
    result.den = b * c;
    result.simplify();
    return result;
 }
 
 Rational& Rational::operator+=(const Rational &rhs) {
    int a = num;
    int b = den;
    int c = rhs.getNumerator();
    int d = rhs.getDenominator();
    this->num = a * d + b * c;
    this->den = b * d;
    this->simplify();
    return *this;
 }
 
 Rational & Rational::operator-=(const Rational &rhs) {
    int a = num;
    int b = den;
    int c = rhs.getNumerator();
    int d = rhs.getDenominator();
    this->num = a * d - b * c;
    this->den = b * d;
    this->simplify();
    return *this;
 }
 
 Rational Rational:: operator-() const {
    Rational result(*this);
    result.num *= -1;
    result.simplify();
    return result;
 }
 
 int Rational::getNumerator() const {
     return num;
 }
 
 int Rational::getDenominator() const {
     return den;
 } 
 
 std::ostream &operator<<(std::ostream &out, const Rational &rat) {
     if (rat.getNumerator() == 0) {
         cout << 0;
     } else if (rat.getDenominator() == 1) {
        cout << rat.getNumerator();
     } else {
     cout << rat.getNumerator();
     cout << '/';
     cout << rat.getDenominator();
     }
     return out;
 }
 
std::istream &operator>>(std::istream &in, Rational &rat) {
    int num, den;
    char s;
    if(in >> num >> s >> den && s == '/') {
        rat = {num, den};
        rat.simplify();
    }
    return in;
}
 
 
