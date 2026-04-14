//Terry Addey
//HW 5 Question 1
#include <iostream> 
using namespace std; 


//BicycleSpeedometer Class Definition 
class BicycleSpeedometer {

//store distance and time as private members
private:
    double distance; 
    double time; 

//public member functions    
public:
    BicycleSpeedometer();
    void set_distance(double dist);
    void set_time(double t);
    double averagespeed();
    void display();
};
//Constructor and member function implementations
BicycleSpeedometer::BicycleSpeedometer() {
    distance = 0.0;
    time = 0.0;
}

void BicycleSpeedometer::set_distance(double dist) {
    distance = dist;
}

void BicycleSpeedometer::set_time(double t) {
    time = t;
}

double BicycleSpeedometer::averagespeed() {
    if (time == 0) return 0;
    return (distance * 60) / time; // Convert to MPH
}

void BicycleSpeedometer::display() {
    cout << "Distance: " << distance << " miles" << endl;
    cout << "Time: " << time << " minutes" << endl;
    cout << "Average Speed: " << averagespeed() << " MPH" << endl;
}

int main() {

  double d, t;
    cout << "Enter distance (miles): ";
    cin >> d;
    cout << "Enter time (minutes): ";
    cin >> t;
    BicycleSpeedometer B1;
    B1.set_distance(d);
    B1.set_time(t);
    B1.display();
    return 0; 
}