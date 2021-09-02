#include "frac.h"
#include <iostream>

using namespace std;

int main() {
  frac f1(9, 6); // calling a parameterized class constructor
  frac f2;       // default constructor
  cout << "\nEnter a fraction in the form of 'a/b' :";
  cin >> f2; // test >>

  cout << "\nf1 is " << f1 << " and f2 is " << f2 << endl; // test <<
  cout << "\nIs f1 equal to f2? " << boolalpha << (f1 == f2)
       << endl;       // is f1==f2?
  frac sum = f1 + f2; // test assignment and addition
  cout << "The sum is " << sum;
  cout << endl;
  cout << "\nReturn the negative of sum " << -sum << endl;
  frac copysum(-sum); // duplicate the result by using copy constructor
  cout << "\nIs sum equal to copysum? " << boolalpha << (sum == copysum)
       << endl;

  cout << "\nReturn the negative negative of sum " << -(-sum) << endl;

  cout << "\nFind " << sum << " + " << 4 << " = " << sum + 4;
  cout << "\nFind " << 4 << " + " << sum << " = " << 4 + sum;
  cout << "\nThis uses the second constructor to convert an integer to a "
          "fraction. ";
  cout << "The compiler is pretty smart!" << endl;
  cout << "\nLet's try '='. f1 was " << f1 << " and sum is " << sum;
  f1 = sum;
  cout << "\nAfter the assignment such as f1=sum. We have f1=" << f1 << endl;

  // continue your experiments
  cout << "\nTry subtraction, multiplication, ....";
  return 0;
}
