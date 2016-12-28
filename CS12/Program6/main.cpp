#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int, int);

bool diophantine(int, int, int, int&, int &);

int main() {

  int a, b, c, x, y;

  cout << "Enter a b c" << endl;
  cin >> a >> b >> c;
  cout << endl;

  cout << "Result: ";
  if (diophantine(a, b, c, x, y)) {
    cout << x << " " << y << endl;
  } 
  else {
    cout << "No solution!" << endl;
  }

  return 0;
}

//Finds the greatest common denominator of two numbers by continuously subtracting until numbers are equal
int GCD(int num1, int num2) {
  int gcd = 0;
  if(num1 < 0) {
    num1 = num1 * -1;
  }
  if(num2 < 0) {
    num2 = num2 * -1;
  }
  if (num1 == num2) {
    gcd = num1;
  }
  else {
    if (num1 > num2) {
      gcd = GCD(num1 - num2, num2);
    }
    else {
      gcd = GCD(num1, num2 - num1);
    }
  }
  return gcd;
}

/* Returns true if a solution was found and false if there is no solution.
  x and y will contain a solution if a solution was found. 
  This function will NOT output anything.
*/
bool diophantine(int a, int b, int c, int& x, int& y) {
  //Conditions that need to be satisfied in order to use the recursive diophantine function
  //If c is a multiple of the GCD of a and b
  if(c % GCD(a, b) == 0) {
    //Part of the recursive function once the equation has been simplified down enough
    //Such that a can be divided evenly by b
    if(a % b == 0) {
      x = 0;
      y = c / b;
      return true;
    }
    //Follow the basic steps written in zybooks
    //So 15x + 21y = 120 would simplify down to 21x + 15y = 120
    //Which would simplify down to 15x + 6y = 120
    //Which would simplify down to 6x + 3y = 120
    //The final simplified equation will always have a be greater than b since we switch r and b
    //Thus, this will satisfy a % b == 0. We will get a sufficient answer to y
    int remain = a % b;
    int quotient = a / b;
    int u = (quotient * x) + y;
    int v = x;
    diophantine(b, remain, c, u, v);
    //The final two steps set x and y to the proper values after the recursive recalls have been completedss
    x = v;
    y = u - (quotient * x);
    return true;
  }
  else {
    return false;
  }
}