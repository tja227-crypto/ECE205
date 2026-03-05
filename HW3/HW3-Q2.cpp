#include <iostream> //library for input and output 
#include <string> //for string 
#include <cmath> //math functions
using namespace std; 
//Homework Question 2
// triangle function
void arbitrarytriangle(double a, double b, double c, double& area, double& perimeter); 
int main () {
    char choice = 'y'; 
    while (choice == 'y' || choice == 'Y') { 
        double a; 
        double b; 
        double c; 
        double area; 
        double perimeter; 
        cout << "Enter side a of the triangle: " << endl; 
        cin >> a; 
        cout << "Enter side b of the triangle: " << endl; 
        cin >> b; 
        cout << "Enter side c of the triangle: " << endl; 
        cin >> c; 
        arbitrarytriangle(a, b, c, area, perimeter);
        cout << "Area of the triangle: " << area << endl;
        cout << "Perimeter of the triangle: " << perimeter << endl; 
        cout << "Would you like to perform another calculation? (y/n): " << endl; 
        cin >> choice; 
    }
    return 0;
}

//Homework Question 2 Arbitrary Triangle Function
void arbitrarytriangle(double a, double b, double c, double& area, double& perimeter
) {
    //check for valid triangle 
    if ( a + b <= c || a + c <= b || b + c <= a) {
        cout << "Invalid triangle. " << endl;
        area = 0; 
        perimeter = 0; 
        return; 
    }
    else {
        //calculate area and perimeter for valid triangle
        perimeter = a + b + c; 
        double s = perimeter / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c)); 
    }

}

