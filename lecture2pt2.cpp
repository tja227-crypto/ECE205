#include <iostream> 
#include <string> //for string 
using namespace std;

int year; //enroll year
int month; // (Jan-Dec, 1-12)

int main() {
    cout << "Enter the year" << endl; 
    cin >> year; 
    cout << endl;
    cout << "Enter the month" << endl; 
    cin >> month; 
    cout << endl;

if (month==1 || month==3 || month==5 || month==7 || month==9 || month==11)
    {
        cout << "The month has 31 days" << endl;
    }
    
    else if (month==4 || month==6 || month==10 || month==12)
        {
            cout << "The month has 30 days" << endl;

        }    
        else if (((year%4)==0) && (month==2))
            {
                cout << "The month has 29 days" << endl;
            }
            
    
    return 0;
}