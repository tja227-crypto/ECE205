#include <iostream> 
#include <string> //for string 
using namespace std;

int year; //enroll year
string name; 

int main() {
    cout << "What is your enrolled year" << endl; 
    cin >> year; 
    cout << endl;

    cout << "What is your name" << endl; 
    cin >> name; 
    cout << endl;

    cout << "My name is: " << name << "and my enrolled year is: " << year << endl;
    
    return 0;
}
