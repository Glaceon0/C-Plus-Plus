#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num;
    int *ptr2 = ptr;
    cout << ptr2;
    
    return 0;
}