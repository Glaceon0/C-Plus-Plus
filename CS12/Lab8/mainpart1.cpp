#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;
   return 0;
}

void flipString(string &line){
    if(line.size() <= 1){
        return;
    }
    string temp_string = line.substr(0, line.size() - 1);
    flipString(temp_string);
    line = line.at(line.size() - 1) + temp_string;
    return;
}