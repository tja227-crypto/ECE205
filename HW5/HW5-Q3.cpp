//Terry Addey 
//Homework 5, Question 3 

#include <iostream>
#include <vector>
using namespace std;

//based off the code starter professor provided in class
class Pizza
{
private:
    int type;       // 1 = deep dish, 2 = hand tossed, 3 = pan
    int size;       // 1 = small, 2 = medium, 3 = large
    int toppings;   // number of toppings

public:
    // constants for type
    static const int DEEP_DISH = 1;
    static const int HAND_TOSSED = 2;
    static const int PAN = 3;

    // constants for size
    static const int SMALL = 1;
    static const int MEDIUM = 2;
    static const int LARGE = 3;

    // default constructor
    Pizza()
    {
        type = HAND_TOSSED;
        size = SMALL;
       toppings = 0;
    
    }

    // parameterized constructor
    Pizza(int t, int s, int top)
    {
        /*setType(t);
        setSize(s);
        setToppings(top);*/
        type = t; size = s; toppings = top;

    }

    // mutators 
    void setType(int t)
    {
        type = t;
    }
    // mutators 
    void setSize(int s)
    {
        size = s;
    }
    // mutators 
    void setToppings(int t)
    {
        toppings = t;
    }

    // accessors
    int getType()
    {
        return type;
    }
    // accessors
    int getSize()
    {
        return size;
    }
    // accessors
    int getToppings()
    {
        return toppings;
    }
    // compute price based on size and toppings
    double computePrice() const;
    void outputDescription() const;

};

//constructor and member function implementations
double Pizza::computePrice() const
{
    double price = 0.0;

    // base price based on type
    switch (type)
    {
        case DEEP_DISH:
            price += 10.0;
            break;
        case HAND_TOSSED:
            price += 8.0;
            break;
        case PAN:
            price += 9.0;
            break;
        default:
            break;
    }

    // additional cost based on size
    switch (size)
    {
        case SMALL:
            price += 0.0;
            break;
        case MEDIUM:
            price += 2.0;
            break;
        case LARGE:
            price += 4.0;
            break;
        default:
            break;
    }

    // additional cost for toppings
    price += toppings * 1.5;

    return price;
}
// output pizza description
void Pizza::outputDescription() const
{
    cout << "Pizza Type: ";
    switch (type)
    {
        case DEEP_DISH:
            cout << "Deep Dish";
            break;
        case HAND_TOSSED:
            cout << "Hand Tossed";
            break;
        case PAN:
            cout << "Pan";
            break;
        default:
            cout << "Unknown";
            break;
    }
    cout << endl;

    cout << "Pizza Size: ";
    switch (size)
    {
        case SMALL:
            cout << "Small";
            break;
        case MEDIUM:
            cout << "Medium";
            break;
        case LARGE:
            cout << "Large";
            break;
        default:
            cout << "Unknown";
            break;
    }
    cout << endl;

    cout << "Number of Toppings: " << toppings << endl;
}


class order {
    vector <Pizza> Pizzas;
public:
    void add_pizza(const Pizza& p)
    {
        Pizzas.push_back(p);
    }
    void add_pizza(int type, int size, int toppings)
    {
        Pizza p(type, size, toppings);
        Pizzas.push_back(p);
    }

    void outputOrder() const
    {
        double totalPrice = 0.0;
    if (Pizzas.empty())
    {
        cout << "No pizzas in the order." << endl;
        
    }
    for (size_t i = 0; i < Pizzas.size(); i++)
    {
        cout << "Pizza #" << i + 1 << ": ";
        Pizzas[i].outputDescription();
        cout << "Price: $" << Pizzas[i].computePrice() << endl << endl;
        totalPrice += Pizzas[i].computePrice();
    }
    cout << "Total Order Price: $" << totalPrice << endl;

}
};

int main()
{
    // create pizza objects
    Pizza pizza1(1, 1, 1);
    Pizza pizza2(2, 2, 2);
    
    // output details for pizza1
    pizza1.outputDescription();
    cout << "Price: $" << pizza1.computePrice() << endl;
    cout << endl;

    // output details for pizza2
    pizza2.outputDescription();
    cout << "Price: $" << pizza2.computePrice() << endl;

    // create orders and add pizzas
    order order1;
    order1.add_pizza(pizza1);
    order1.add_pizza(pizza2);

    order order2;
    order2.add_pizza(pizza1);
    order2.add_pizza(pizza2);
    order2.add_pizza(pizza1);

    order1.outputOrder();
    order2.outputOrder();

    return 0;
}