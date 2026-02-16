#include <iostream> //library for input and output 
#include <string> //for string 
#include <cmath> //math functions
using namespace std; //meant to prevent name conflicts 
double height;
double weight; 
double age; 
double hat_size;
double jacket_size;
double waist_size;
double waist_adder;
//Homework Question 3
//user's height, weight, and age cloth size calculator 
void calculateClothSizes(double height, double weight, double age);

int main() {
    cout << "Enter your height in inches: " << endl; //print input 
    cin >> height; //input for height 
    cout << "Enter your weight in pounds: " << endl; //print input 
    cin >> weight; //input for weight 
    cout << "Enter your age: " << endl; //print input 
    cin >> age; //input for age 
    calculateClothSizes(height, weight, age); //function call to calculate cloth sizes
    return 0;
}
void calculateClothSizes(double height, double weight, double age) {
    
    hat_size = (weight / height) * 2.9; //hat size calculation
    jacket_size = (height * weight) / 288.0; //jacket size calculation
    if (age > 30) {
        jacket_size = jacket_size + ((age - 30) / 10.0) * (1 / 8.0); //jacket size calculation with adder
    }
    waist_size = weight / 5.7; //waist size calculation
    if (age > 28) {
        waist_adder = ((age - 28) / 2.0) * (1 / 10.0); //waist size adder calculation
        waist_size = waist_size + waist_adder; //waist size calculation with adder
    }
    cout.setf(ios::fixed); //sets the float to fixed
    cout.setf(ios::showpoint); //shows the decimal point
    cout.precision(2); //sets the precision to 8 decimal places
    cout << "Your hat size is: " << hat_size << endl; //print hat size
    cout << "Your jacket size is: " << jacket_size << endl; //print jacket
    cout << "Your waist size is: " << waist_size << endl; //print waist size
}


