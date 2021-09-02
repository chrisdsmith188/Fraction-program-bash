#ifndef FRAC_H
#include "frac.h"
#endif
#include <cmath>
#include <cstdlib>

//@param a and b are integers
//@return the gcd of a and b
// We use Euclidean Algorithm
int gcd(int a, int b) {
  int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}

// defining member functions/operators must have "frac::"
void frac::reduce() {
  int newNum = numerator;
  int newDen = denominator;
  if (newDen == 0) {
    cout << "\n Undefined!\n";
  }
  if (newNum == 0 && newDen != 0) {
    numerator = 0;
    denominator = 1;
    return;
  }
  int temp = gcd(abs(newNum), abs(newDen));
  if ((newNum >= 0 && newDen >= 0) || (newNum < 0 && newDen < 0)) {
    numerator = abs(newNum);

  } else {
    numerator = abs(newNum) * (-1);
  }
  numerator = numerator / temp;
  denominator = abs(newDen) / temp;
}

// constructor
frac::frac() {
  numerator = 0;
  denominator = 1;
}

// constructor
frac::frac(int I) {
  numerator = I;
  denominator = 1;
}

// constructor
frac::frac(int newNum, int newDen) {
  numerator = newNum;
  denominator = newDen;
  reduce();
}

// the friend functions and operators are not member. Thus don't need
//"frac::"
// It overloads >> to read in fractions of the form "num/den"
istream &operator>>(istream &ins, frac &A) {
  int num, den;
  char bslash;
  // input should look like num/den such as 5/6, 103/205, etc.
  ins >> num >> bslash >> den;
  if (bslash != '/') {
    cout << "\nWrong input format\n";
    exit(1);
  }
  A.numerator = num;
  A.denominator = den;
  A.reduce();
  return ins;
}

ostream &operator<<(ostream &outs, const frac &A) {
  outs << A.numerator << "/" << A.denominator;
  return outs;
}

frac operator+(const frac &A, const frac &B) {
  int num = A.denominator * B.numerator + A.numerator * B.denominator;
  int den = A.denominator * B.denominator;
  return frac(num, den);
}

bool operator==(const frac &A, const frac &B) {
  return (A.numerator * B.denominator == A.denominator * B.numerator);
}

// member version of negative (not subtraction)
frac frac::operator-() { return frac(-numerator, denominator); }
