//calculate the length of the room 
//demonstrate some math functions from cmath
//random number generater
#include <iostream> 
#include <cmath> 
#include <cstdlib> //for rand() and srand()
using namespace std; 
//cal_cost function - forward declaration
double cal_cost();

int main() 
{
    double area, length; 
    cout << "Enter the area" << endl; 
    cin >> area; 

    length=sqrt(area);
    cout << "The length of the room is: " << length << endl;

    int a =-5;
    float b =-3.5f;
    float c = 2.3;
    cout << "abs: " << abs(a) <<endl; //expecting 5 
    cout << "fabs: " << fabs(b) <<endl; //expecting 5 
    cout << "ceil: " << ceil(c) <<endl; //expecting 3
    cout << "floor: " <<floor(c)<<endl; //expecting 2     
    cout << "round: " << round(c) << endl; //expecting 2

    int number; 
    for (int i=0; i<10; i++){
        srand(i); //seed the random number generator
        number =( rand() % 10) + 1;
        cout << "Random number: " << number << endl;
    }
    cout << "The maximum number generated is: " << RAND_MAX << endl;

    cout << "cost is: " << cal_cost() << endl; 
    return 0; 
}
double cal_cost()//input list price per square foot and area
{
    double area, sqr_ft_cost; 
    cout << "Enter the area" << endl; 
    cin >> area; 
    cout << "Enter the cost per square foot" << endl; 
    cin >> sqr_ft_cost; 

    double total_cost = area * sqr_ft_cost; 
    cout <<"Total cost is: " << total_cost << endl; 
    return total_cost;}
