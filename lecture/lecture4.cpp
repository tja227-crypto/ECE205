#include <iostream>
using namespace std;

int area (int t)//square 
{
    int result; 
    result = pow(t,2);
    return result;
}

float area(float t1, float t2) //circle 
{
    float result;
    result = 3.14159 * t1 * t2;
    return result;
}

int main() {

    int x1= area(5)

}
