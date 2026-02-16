#include <iostream> //library for input and output 
#include <string> //for string 
using namespace std; //meant to prevent name conflicts 
//add prompt for user to go again or not 
int main () {
    cout << "Enter a positive integer: " << endl; //print input
    int n;
    cin >> n;
    if (n > 0) {
        cout << "The number is positive." << endl;
    } else {
        cout << "The number is not positive." << endl;
    }
    cout << "Would you like to enter another number? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        main();
    }
    return 0;
}