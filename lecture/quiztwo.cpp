#include <iostream> //library for input and output 
#include <string> //for string 
using namespace std; //meant to prevent name conflicts
//function to check if three numbers are increasing in order 

bool inOrder(int a, int b, int c);

int main() {
    cout << "Enter three integers: " << endl;
    int a, b ,c ; 
    cin >> a >> b >> c; //input for three integers 
    if (inOrder(a, b, c)) {
        cout << "The numbers are in increasing order." << endl;
    } else {
        cout << "The numbers are not in increasing order." << endl;
    }
    return 0;
}

bool inOrder(int a, int b, int c) {
    if (a <= b && b <= c) {
        return true; //numbers are increasing
    } else {
        return false; //numbers are not increasing
    }
}