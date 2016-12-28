#include "WordLadder.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
try {
    string name;
    cout << "Name of the dictionary file?" << endl;
    cin >> name;
    WordLadder object(name);
    
    string start;
    cout << "Enter a five letter word" << endl;
    cin >> start;
    
    string end;
    cout << "Enter another five letter word" << endl;
    cin >> end;
    
    string outputFile;
    cout << "And finally, enter the file to which you want the word ladder to be outputted to" << endl;
    cin >> outputFile;
    
    cin.clear();
    
    object.outputLadder(start, end, outputFile);
    
    return 0;
  }
  catch(const out_of_range& excpt) {
    cout << excpt.what() << endl;
    return 0;
  }
  catch(const length_error& excpt) {
    cout << excpt.what() << endl;
    return 0;
  }
  catch(const range_error& excpt) {
    cout << excpt.what() << endl;
    return 0;
  }
  catch(const invalid_argument& excpt) {
    cout << excpt.what() << endl;
    return 0;
  }
}