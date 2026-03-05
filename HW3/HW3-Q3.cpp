//Terry Addey 
//ECE 205
//Homework 3, Question 3
#include <iostream>
#include <string> 
using namespace std;
//this program converts the time from a 24-hour format to a 12-hour format
//the reason that I also changed to 12-hour format here is because I am making use of the code I made for my midterm exam 
string period1, period2;

int getDifference(int time1, int time2); //function to calculate the difference between the two times 

int main()
{ 
    //input for the start and end times 
    int time1;
    cout << "Start time in 24-hour format: "; 
    cin >> time1; 
    int time2; 
    cout << "End time in 24-hour format: ";
    cin >> time2;
    //converting times to 12 hour format for time 1  
    int hours1 = time1 / 100;
    int minutes1 = time1 % 100;
    if (hours1 >= 12) {
        period1 = "PM";
    } else {
        period1 = "AM";
    }
    if (hours1 < 12) {
        hours1 = hours1; 
    } else if (hours1 == 12) {
        hours1 = 12; 
    } else {
        hours1 = hours1 - 12; 
    }
    if (minutes1 < 10) {
        cout << "Start time in 12-hour format: " << hours1 << ":0" << minutes1 << " " << period1 << endl; 
    } else {
        cout << "Start time in 12-hour format: " << hours1 << ":" << minutes1 << " " << period1 << endl;
    }
    //converting times to 12 hour format for time 2
    int hours2 = time2 / 100;
    int minutes2 = time2 % 100;
     if (hours2 >= 12) {
        period2 = "PM";
    } else {
        period2 = "AM";
    }
    if (hours2 < 12) {
        hours2 = hours2; 
    } else if (hours2 == 12) {
        hours2 = 12; 
    } else {
        hours2 = hours2 - 12; 
    }
    if (minutes2 < 10) {
        cout << "End time in 12-hour format: " << hours2 << ":0" << minutes2 << " " << period2 << endl; 
    } else {
        cout << "End time in 12-hour format: " << hours2 << ":" << minutes2 << " " << period2 << endl;
    }

    int diff = getDifference(time1, time2);
    cout << "The difference in minutes is: " << diff << endl;
    return 0;
    
}

int getDifference(int time1, int time2)
{
    int hours1 = time1 / 100;
    int minutes1 = time1 % 100;
    int hours2 = time2 / 100;
    int minutes2 = time2 % 100;
    int totalMinutes1 = hours1 * 60 + minutes1;
    int totalMinutes2 = hours2 * 60 + minutes2;
    if (totalMinutes2 < totalMinutes1) {
        totalMinutes2 += 24 * 60; // add 24 hours in minutes if time2 is earlier than time1
    }

    return totalMinutes2 - totalMinutes1;

}