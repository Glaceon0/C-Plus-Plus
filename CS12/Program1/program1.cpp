#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

void readData(string filename, vector<double>& flightAngle, vector<double>& cLift);

void displayVectors(const vector<double>& v, const vector<double>& v2);

unsigned findSmallest(const vector<double>& v, unsigned start);

void reorder(vector<double>& v, vector<double>& v2);

bool isOrdered(const vector<double>& v);

double interpolation(double userInput, const vector<double>& v, const vector<double>& v2);

int main() {
    string filename;
    vector<double> flightAngle;
    vector<double> cLift;
    double userInput;
    
    
    cout << "Enter name of input data file:" << endl;
    cin >> filename;
    cout << endl;
    
    readData(filename, flightAngle, cLift);
    
    displayVectors(flightAngle, cLift);
    
    reorder(flightAngle, cLift);
    
    displayVectors(flightAngle, cLift);
    
    if(isOrdered(flightAngle)) {
        cout << "Enter a flight angle path" << endl;
        cin >> userInput;
        cout << "Corresponding coefficient of life is: " << interpolation(userInput, flightAngle, cLift) << endl;
    }
    
    return 0;
}

void readData(string filename, vector<double>& flightAngle, vector<double>& cLift) {
    ifstream inFS;
    double inputV1;
    double inputV2;
    
    inFS.open(filename.c_str());
    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    
    while(!inFS.eof()) {
        inFS >> inputV1;
            if(inFS.good()) {
            flightAngle.push_back(inputV1);
        }
        inFS >> inputV2;
            if(inFS.good()) {
            cLift.push_back(inputV2);
        }
    }
    return;
}

void displayVectors(const vector<double>& v, const vector<double>& v2) {
    cout << "Displaying flight-path angles: ";
    for(unsigned i = 0; i < v.size(); ++i) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    
    cout << "Displaying coefficients of lift: ";
    for(unsigned i = 0; i < v2.size(); ++i) {
        cout << v2.at(i) << " ";
    }
    cout << endl;
    
    return;
}

unsigned findSmallest(const vector<double>& v, unsigned start) {
    unsigned pos = start;
    for(unsigned i = start + 1; i < v.size(); ++i) {
        if(v.at(i) < v.at(pos)) {
            pos = i;
        }
    }
    return pos;
}

void reorder(vector<double>& v, vector<double>& v2) {
    unsigned redo = 0;
    for(unsigned i = 0; i < v.size(); ++i) {
        redo = findSmallest(v, i);
        swap(v.at(i), v.at(redo));
        swap(v2.at(i), v2.at(redo));
    }
    return;
} 

bool isOrdered(const vector<double>& v) {
    for(unsigned i = 0; i + 1 < v.size(); ++i) {
        if(v.at(i) > v.at(i + 1)) {
            return false;
        }
    }
    return true;
}

// implement calculations if number is not found in vector v
// find a method to determine which numbers the userInput falls between
double interpolation(double userInput, const vector<double>& v, const vector<double>& v2) {
    //implement check if number already exists withinn vector v
    double output = 0.0;
    for(unsigned i = 0; i < v.size(); ++i) {
        if(abs(v.at(i) - userInput) < 10e-6) {
            return v2.at(i);
        }
    }
    for(unsigned i = 0; i + 1 < v.size(); ++i) {
            if(v.at(i) < userInput && v.at(i + 1) > userInput) {
                output = v2.at(i) + (userInput - v.at(i))/(v.at(i + 1) - v.at(i)) * (v2.at(i + 1) - v2.at(i));
                return output;
            }
        }
        return UINT_MAX;
    }
    

