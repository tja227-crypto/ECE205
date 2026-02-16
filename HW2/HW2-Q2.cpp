#include <iostream> //library for input and output 
#include <string> //for string 
#include <cmath> //math functions
#include <fstream> //file input and output
using namespace std; //meant to prevent name conflicts 

double computeAverage (int n1, int n2, int n3, int n4, int n5); //function to compute average
double computeStandardDeviation (int n1, int n2, int n3, int n4, int n5, double average); //function to compute standard deviation

//Homework Question 2
int main(){

ifstream inputfile; //input file stream
ofstream outputfile; //output file stream 
int n1, n2, n3, n4, n5; //test scores 

//read data from text file; 
inputfile.open("testscores.txt");
inputfile >> n1;
inputfile >> n2;
inputfile >> n3; 
inputfile >> n4; 
inputfile >> n5; 

double average = computeAverage(n1, n2, n3, n4, n5); //average calculation
double standard_deviation = computeStandardDeviation(n1, n2, n3, n4, n5, average); //standard deviation calculation

outputfile.open("results.txt"); //open output file
//write data in the file 
outputfile.setf (ios::fixed);
outputfile.setf (ios::showpoint);
outputfile.precision(2);

outputfile << "The average is: " << average << endl;
outputfile << "The standard deviation is: " << standard_deviation << endl;


//display the results 
cout << "The average is: " << average <<endl; 
cout << "The standard deviation is: " << standard_deviation << endl;

inputfile.close(); //close input file
outputfile.close(); //close output file
return 0; //end of program  
}
double computeAverage (int n1, int n2, int n3, int n4, int n5) {
    double average = (n1 + n2 + n3 + n4 + n5) / 5.00; //average calculation
    return average; //return the average
}
double computeStandardDeviation (int n1, int n2, int n3, int n4, int n5, double average) {
    double sum_of_squares = (n1 - average)*(n1 - average) + (n2 - average)*(n2 - average) + (n3 - average)*(n3 - average) + (n4 - average)*(n4 - average) + (n5 - average)*(n5 - average);
    double standard_deviation = sqrt(sum_of_squares / 5.00);
    return standard_deviation; //return the standard deviation
}