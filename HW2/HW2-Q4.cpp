#include <iostream> //library for input and output
#include <cstdlib> // for rand() and srand() 
using namespace std; 

int w1, w2, w3, w4; 

void selectWinners() {
    // first winner:
    w1 = rand() % 25 + 1;

    // second winner:
    w2 = w1; 
    while (w2 == w1) {
        w2 = rand() % 25 + 1;
    }

    // third winner:
    w3 = w1; 
    while (w3 == w1 || w3 == w2) {
        w3 = rand() % 25 + 1;
    }

    // fourth winner:
    w4 = w1;
    while (w4 == w1 || w4 == w2 || w4 == w3) {
        w4 = rand() % 25 + 1;
    }

    cout << "The 4 prize winners are: ";
    cout << w1 << " " << w2 << " " << w3 << " " << w4 << endl;
}

int main() {
int userInput;
    cout << "Enter any number to shuffle the winners: ";
    cin >> userInput;

    // shuffles the random number generator based on your input
    srand(userInput); 
    selectWinners();  
    return 0;
}