#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string filename);

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << "Sum: " << fileSum(filename) << endl;
   
   return 0;
}

int fileSum(string filename) {
    ifstream inFS;
    int sumNum = 0;
    int inputNum = 0;
    
    inFS.open(filename.c_str());
    
    if (!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    
    while (!inFS.eof()) {
        inFS >> inputNum;
        if(inFS.good()) {
        sumNum += inputNum;
        }
    }
    return sumNum;
}