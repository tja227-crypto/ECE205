#include <iostream> //library for input and output 
#include <string> //for string 
#include <cmath> //math functions
using namespace std; //meant to prevent name conflicts 

//Homework Question 1 
//functions input, conversion, and output 
void input(); 
void conversion(int hour_24, int minute_24,char &am_pm); 
void output(int hour_12, int minute_24, char am_pm); 

int main () {
    char choice = 'y'; 
    while (choice == 'y' || choice == 'Y') { 
        input(); 
        cout << "Would you like to perform another calculation? (y/n): " << endl; 
        cin >> choice; 
    }
   
    return 0;
}
//input function
void input() {
    int hour_24;
    int minute_24;
    char am_pm; 
    cout << "Enter hour in 24-hour notation (0-23): " << endl; 
    cin >> hour_24;
    cout << "Enter minute in 24-hour notation (0-59): " << endl; 
    cin >> minute_24; 
    conversion(hour_24, minute_24, am_pm); 
}

//conversion function
void conversion(int hour_24, int minute_24, char &am_pm) {
    int hour_12; 

    if (hour_24 == 0) { 
        hour_12 = 12;
        am_pm = 'A';
    } else if (hour_24 < 12) { 
        hour_12 = hour_24;
        am_pm = 'A';
    } else if (hour_24 == 12) { 
        hour_12 = 12;
        am_pm = 'P';
    } else { 
        hour_12 = hour_24 - 12;
        am_pm = 'P';
    }
    output(hour_12, minute_24, am_pm); 
}
//output function
void output(int hour_12, int minute_24, char am_pm) {
    if (minute_24 < 10)
    cout << hour_12 << ":0" << minute_24 << " " << am_pm;
else
    cout << "Time in 12-hour notation: " << hour_12 << ":" << minute_24 << " " << am_pm << endl; 
}

