#include <iostream>
using namespace std;

void fillArray(double array[], int arraySize);

double mean(const double array[], int arraySize);

void remove(double array[], int arraySize, int index);

void display(const double array[], int arraySize);

int main() {
    int arraySize = 10;
    double array[arraySize];
    int index = 0;
    
    fillArray(array, arraySize);
    
    cout << "Mean: " << mean(array, arraySize) << endl << endl;
    
    cout << "Enter index of value to be removed: " << endl; 
    cin >> index;
    
    cout << "Before removing value: ";
    display(array, arraySize);
    cout << endl;
    
    remove(array, arraySize, index);
    
    cout << "After removing value: ";
    display(array, arraySize - 1);
    cout << endl;
    
    return 0; 
}
 
void fillArray(double array[], int arraySize) {
    double userInput = 0.0;
    cout << "Enter " << arraySize << " values:" << endl << endl;
    for(int i = 0; i < arraySize; ++i) {
        cin >> userInput; 
        array[i] = userInput;
    }
}

double mean(const double array[], int arraySize) {
    double arrayMean = 0;
    for(int i = 0; i < arraySize; ++i) {
        arrayMean += array[i];
    }
    return arrayMean / static_cast<double> (arraySize);
}

void remove(double array[], int arraySize, int index) {
    for(int i = index; i < arraySize - 1; ++i) {
        array[i] = array[i + 1]; 
    }
    return;
}

void display(const double array[], int arraySize) {
    for(int i = 0; i < arraySize - 1; ++i) {
        cout << array[i] << ", ";
    }
    cout << array[arraySize - 1];
}