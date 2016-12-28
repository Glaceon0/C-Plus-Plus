#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(string filename, char ch);

int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << "Enter a character: ";
   cin >> ch;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}

int charCnt(string filename, char ch) {
   
   ifstream fin;
   int cnt = 0;
   
   fin.open(filename.c_str());
   if (!fin.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(1);
   }
   
   char input;
   while (!fin.eof()) {
       fin >> input;
      if (input == ch && fin.good()) {
         ++cnt;
      }
   }
   fin.close();   
   return cnt;
}