#include "Jug.h"

int main() {
  string solution1;
  Jug head(3, 5, 4, 1, 2, 3, 4, 5, 6);
  if (head.solve(solution1) != 1) {
    cout << "Error 3" << endl;
  }
  cout << solution1 << endl << endl;
  
  string solution2;
  Jug tail( 3, 5, 4, 1, 1, 1, 1, 1, 2);         
  if(tail.solve(solution2) != 1) {
    cout << "Error 3" << endl;
  }
  cout << solution2 << endl;
}