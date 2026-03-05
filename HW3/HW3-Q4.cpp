//Terry Addey 
//ECE 205
//Homework 3, Question 4
#include <iostream>
using namespace std;

//functions 
void inputWeight(int& pounds, int& ounces); 
void convertWeight(int& pounds, int& ounces, double& weight_KG, double& weight_G); 
void outputWeight(int& pounds, int& ounces , double& weight_KG, double& weight_G); 

int main()
{
    char choice = 'y'; 
     while (choice == 'Y' || choice == 'y'){
        int pounds, ounces; 
        double weight_KG, weight_G; 
        inputWeight(pounds, ounces); 
        convertWeight(pounds, ounces, weight_KG, weight_G); 
        outputWeight(pounds, ounces , weight_KG, weight_G); 
        cout << "Do you want to convert another weight? (Y/N): "; 
        cin >> choice; 
    }  

    return 0;
}
//function to input weight in pounds and ounces 
void inputWeight(int& pounds, int& ounces) {
    cout << "Enter Weight (pounds ounces): "; 
    cin >> pounds >> ounces; 
}
//function to convert weight from pounds and ounces to kilograms and grams
void convertWeight(int& pounds, int& ounces, double& weight_KG, double& weight_G) {
    double OUNCES_IN_POUND = 16; 
    double GRAMS_IN_KG = 1000; 
    const double POUNDS_IN_KG = 2.2046; 

    double totalPounds = pounds + (ounces / OUNCES_IN_POUND); 
    weight_KG = (totalPounds / POUNDS_IN_KG); 
    weight_G = weight_KG * GRAMS_IN_KG;
}
//
void outputWeight(int& pounds, int& ounces , double& weight_KG, double& weight_G) {

    int kg = (int)weight_KG;
    int grams = (int)weight_G % 1000;

    cout << pounds << "lb " << ounces << "oz is equivalent to "
         << kg << "kg " << grams << "g" << endl;
}