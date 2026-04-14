//Terry Addey 
//HW 5 Question 2
#include <iostream>
using namespace std;

//strings 
const string HAND_TOSSED = "hand tossed";
const string DEEP_DISH = "deep dish";
const string PAN = "pan";
const string SMALL = "small";
const string MEDIUM = "medium";
const string LARGE = "large";

//Pizza Class Definition
class Pizza {
private:
    string type;
    string size;
    int pepperoni_top;
    int cheese_top;
public:
    Pizza();
    void set_type(string t);
    void set_size(string s);
    void set_pepperoni_toppings(int p);
    void set_cheese_toppings(int c);
    string get_type();
    string get_size();
    int get_pepperoni_toppings();
    int get_cheese_toppings();
    void outputDescription();
    double computePrice();
};
int main() {
    // create various pizza objects
    Pizza p1; // hand tossed, medium, 0 toppings
    cout << "Pizza 1:" << endl;
    p1.outputDescription();
    cout << "Price: $" << p1.computePrice() << endl << endl;

    Pizza p2;// deep dish, large, 2 pepperoni, 1 cheese
    p2.set_type(DEEP_DISH);
    p2.set_size(LARGE);
    p2.set_pepperoni_toppings(2);
    p2.set_cheese_toppings(1);
    cout << "Pizza 2:" << endl;
    p2.outputDescription();
    cout << "Price: $" << p2.computePrice() << endl << endl;

    Pizza p3; // pan, small, 1 pepperoni, 3 cheese
    p3.set_type(PAN);
    p3.set_size(SMALL);
    p3.set_pepperoni_toppings(1);
    p3.set_cheese_toppings(3);
    cout << "Pizza 3:" << endl;
    p3.outputDescription();
    cout << "Price: $" << p3.computePrice() << endl << endl;

    Pizza p4; // hand tossed, medium, 0 pepperoni, 2 cheese
    p4.set_type(HAND_TOSSED);
    p4.set_size(MEDIUM);
    p4.set_pepperoni_toppings(0);
    p4.set_cheese_toppings(2);
    cout << "Pizza 4:" << endl;
    p4.outputDescription();
    cout << "Price: $" << p4.computePrice() << endl << endl;

    return 0;
}
//constructor and member function implementations
Pizza::Pizza() {
    type = HAND_TOSSED;
    size = MEDIUM;
    pepperoni_top = 0;
    cheese_top = 0;
}
void Pizza::set_type(string t) {
    type = t;
}
void Pizza::set_size(string s) {
    size = s;
}
void Pizza::set_pepperoni_toppings(int p) {
    pepperoni_top = p;
}
void Pizza::set_cheese_toppings(int c) {
    cheese_top = c;
}
string Pizza::get_type() {
    return type;
}
string Pizza::get_size() {
    return size;
}
int Pizza::get_pepperoni_toppings() {
    return pepperoni_top;
}
int Pizza::get_cheese_toppings() {
    return cheese_top;
}
// output pizza description
void Pizza::outputDescription() {
    cout << "Pizza Type: " << type << endl;
    cout << "Pizza Size: " << size << endl;
    cout << "Pepperoni Toppings: " << pepperoni_top << endl;
    cout << "Cheese Toppings: " << cheese_top << endl;
}
// compute price based on size and toppings
double Pizza::computePrice() {
    double price = 0.0;
    if (size == SMALL) price += 10.0;
    else if (size == MEDIUM) price += 14.0;
    else if (size == LARGE) price += 17.0;

    price += pepperoni_top * 2.0;
    price += cheese_top * 2.0;

    return price;
}


