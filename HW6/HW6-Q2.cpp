//Terry Addey 
//HW 6 Question 2
#include <iostream>
using namespace std;
#include <vector>

//started using professors starter code 

// function prototypes
void deleteRepeatedChars(vector<char>& myVector);
void selectionSort(vector<char>& myVector);

int main()
{
    vector<char> myVector; // vector to store user input
    char input; // variable to store user input

    cout << "Enter characters (enter 0 if you want to stop): " << endl; 
    cin >> input; // get user input

    // infinte loop for user input 
    while (input != '0')
    {
        myVector.push_back(input);// add inpit to vector
        cout << "Enter characters (enter 0 to stop): " << endl;
        cin >> input;
    }

    //remove duplicates and sort the vector 
    deleteRepeatedChars(myVector);
    cout << "Testing deleteRepeatedChars function: " << endl;
    selectionSort(myVector);
    cout << "Testing selectionSort function: " << endl;
    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << " ";
    }
    cout << endl;
    return 0;
}

// function to delete repeated characters 
void deleteRepeatedChars(vector<char>& myVector) 
{ 
    for (int i = 0; i < myVector.size(); i++) 
    { 
        for (int j = i + 1; j < myVector.size(); j++) 
        { 
            if (myVector[i] == myVector[j]) 
            { 
                myVector.erase(myVector.begin() + j); 
                j--; 
            } 
        } 
    }
}

// function to sort the vector 
void selectionSort(vector<char>& myVector) 
{ 
    int n = myVector.size(); 
    for (int i = 0; i < n - 1; i++) 
    { 
        int maxIndex = i; 
        for (int j = i + 1; j < n; j++) 
        { 
            if (myVector[j] > myVector[maxIndex]) // for decreasing order
            { 
                maxIndex = j; 
            } 
        } 
        swap(myVector[i], myVector[maxIndex]); 
    } 
}
