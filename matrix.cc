#include <algorithm>
#include <iostream>
using namespace std;

// class of integer matrices
class SqMatrix {
private:
  int dim; // the dimension of the sq matrix
  int **M; // the sq matrix - 2d array
public:
  // default constructor: an nxn zero matrix
  SqMatrix(int n);
  // create an nxn square matrix out of a 2D array.  It does not copy the input.
  // not a copy constructor
  SqMatrix(int n, int **input);
  // copy constructor : "=" assignment, destructor, and copy constructor.
  // If you need one, you need all.
  SqMatrix(const SqMatrix &A);
  // destructor
  ~SqMatrix();
  // We did a copy constructor and a destructor. Let's try "=" assignment.
  // SqMatrix &operator=(const SqMatrix &A);
  //==
  // friend bool operator==(const SqMatrix &A, const SqMatrix &B);
  //+
  friend SqMatrix operator+(const SqMatrix &A, const SqMatrix &B);
  // create one for each of the subtraction and multiplication
  // what about division!? Have fun!

  // Let overload the "insertor" operator to print a nice matrix output format
  friend ostream &operator<<(ostream &outs, const SqMatrix &A);
};

int main() {
  cout << "\nEnter the dimension of the matrix : ";
  int n;
  cin >> n;
  // create 2 2-D arrays
  int **A = new int *[n], **B = new int *[n];
  // just fill the arrays with some data
  for (int i = 0; i < n; i++) {
    A[i] = new int[n];
    B[i] = new int[n];
    for (int j = 0; j < n; j++) {
      A[i][j] = i;
      B[i][j] = j;
    }
  }
  // create 2 matrices out of the arrays.
  SqMatrix MA(n, A), MB(n, B);
  cout << MA << endl;
  cout << " + " << endl;
  cout << MB << endl;
  cout << " = " << endl;
  cout << MA + MB << endl;
  return 0;
}

// constructor: create a zero matrix
SqMatrix::SqMatrix(int n)
    : dim(n) // set dim=n, it takes some work for M
{
  M = new int *[dim];
  for (int i = 0; i < dim; i++) {
    M[i] = new int[dim];
    fill_n(M[i], dim, 0); // Let's fill the 1-D array with 0
  }
}

// constructor.
//
SqMatrix::SqMatrix(int n, int **input) : dim(n) {
  M = new int *[dim];
  for (int i = 0; i < dim; i++) {
    M[i] = new int[dim];
    for (int j = 0; j < dim; j++) {
      M[i][j] = input[i][j];
    }
  }
}

// copy constructor
// duplicate A - a deep copy is usually used
SqMatrix::SqMatrix(const SqMatrix &A) : dim(A.dim) {
  M = new int *[dim];
  for (int i = 0; i < dim; i++) {
    M[i] = new int[dim];
    for (int j = 0; j < dim; j++) {
      M[i][j] = A.M[i][j];
    }
  }
}

// destructor
SqMatrix::~SqMatrix() {
  for (int i = 0; i < dim; i++) {
    delete[] M[i];
  }
  delete[] M;
}

// assume A and B are of the same dimension
SqMatrix operator+(const SqMatrix &A, const SqMatrix &B) {
  int n = A.dim;
  int **temp = new int *[n];
  for (int i = 0; i < n; i++) {
    temp[i] = new int[n];
    for (int j = 0; j < n; j++) {
      temp[i][j] = A.M[i][j] + B.M[i][j];
    }
  }
  return SqMatrix(n, temp);
}

ostream &operator<<(ostream &outs, const SqMatrix &A) {
  for (int i = 0; i < A.dim; ++i) {
    for (int j = 0; j < A.dim; ++j) {
      outs << A.M[i][j] << ' ';
    }
    outs << endl;
  }
  return outs;
}
