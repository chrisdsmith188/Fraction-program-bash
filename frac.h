// frac class declaration
#ifndef FRAC_H
#define FRAC_H
#include <iostream>

using namespace std;

class frac {
private:
  // this fraction is stored in a reduced format
  int numerator;
  int denominator;

public:
  // constructors
  frac();                 // default constractor....create 0/1
  frac(int num);          // create num/1 - i.e. convert an integer to a frac
  frac(int num, int den); // constractor for num/den

  // a public meember function
  // to reduce fractions; such as 4/6 to 2/3.
  // If it is zero, represent it by 0/1
  void reduce();

  /*Wiki: ... operators may be overloaded as member functions or non-member
(friend) functions. The choice of whether or not to overload as a member is
up to the programmer. Operators are generally overloaded as members when they:
1. change the left-hand operand, or
2. require direct access to the non-public parts of an object.

When an operator is defined as a member, the number of explicit parameters
is reduced by one, as the calling object is implicitly supplied as an operand.
Thus, binary operators take one explicit parameter
and unary operators none.
  */

  // note "friend *" is not a member function/operator
  // the operators act on instances that could be different from this instance
  friend istream &operator>>(istream &ins, frac &A);        // input
  friend ostream &operator<<(ostream &outs, const frac &A); // output
  friend frac operator+(const frac &A, const frac &B);      //+
  friend bool operator==(const frac &A, const frac &B);     //==
  // create operator overloads for - (subtraction), * (multiplication)

  // This is a member operator overload - not friend
  // the op - (negative) acts on itself and needs access of the private data
  frac operator-(); // return negative something
};

// not a class member function
//@param a/b: input integers
//@return: gcd of a and b
int gcd(int a, int b);
#endif
