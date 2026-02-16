#include <iostream> //library for input and output 
#include <string> //for string 
#include <cmath> //math functions
using namespace std; //meant to prevent name conflicts 

//Homework Question 1 
double gravitational_constant = 6.673e-8; //gravitational constant

double gravitationalForce(double m1_kg, double m2_kg, double d_cm); //function to calculate the gravitational force 
int main() { 
    //Homework Question 1 
    char choice = 'y'; //will allow the user to repeat the code 
    while (choice == 'y' || choice == 'Y') { //while loop to repeat the code 
        double m1, m2, d; //mass 1, mass 2, mass 3 
        cout << "Enter mass 1 in kilograms: " << endl; //print output 
        cin >> m1; //input for mass 1
        cout << "Enter mass 2 in kilograms: " << endl; //print output 
        cin >> m2; //input for mass 2 
        cout << "Enter distance between the masses in cm: " <<endl;  //print output 
        cin >> d; //input for distance between masses 
        double force = gravitationalForce(m1, m2, d); //gravitational force calculation 
        cout.setf(ios::fixed); //sets the float to fixed
        cout.setf(ios::showpoint); //shows the decimal point
        cout.precision(8); //sets the precision to 8 decimal places
        cout << "Gravitational Force: " << force << " dynes." << endl; 
        cout << "Would you like to perform another calculation? (y/n): " << endl; //ask user if they want to repeat
        cin >> choice; //input for choice
    }
   
    return 0;
}
//Homework Question 1 Function 
double gravitationalForce(double m1_kg, double m2_kg, double d_cm) {
    double d_squared = pow(d_cm, 2); //distance squared calculation
    double force = (gravitational_constant * (m1_kg * 1000) * (m2_kg * 1000)) / d_squared; //gravitational force calculation 
    return force; //return the gravitational force
}
