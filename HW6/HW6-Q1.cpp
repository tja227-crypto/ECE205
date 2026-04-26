//Terry Addey 
//HW 6 Question 1
#include <iostream>
using namespace std;
#include <vector>

//started using professors starter code 
int findMax(vector<int> myVector);

int main()
{
    vector<int> numbers; // vector that stores the user inputs 
    int input;

    cout << "Enter integers (negative number to end): ";
    // infinite loop
    while (true)
    {
        cin >> input; //user input 
        if (input < 0)
        {
            break;
        }
        numbers.push_back(input);// add input to vector
    }

    if (numbers.empty())// check if vector is empty
    {
        cout << "No numbers entered." << endl;
        return 0;
    }

    int max = findMax(numbers);// find the maximum value in the vector
    int bins = (max / 10) + 1; // calculate number of bins needed
    vector<int> histogram(bins, 0); // store count of numbers in each bin 

    for (int num : numbers)
    {
        histogram[num / 10]++; // increment the appropriate bin
    }

    cout << "Histogram:" << endl;
    
    //print histogram 
    for (int i = 0; i < bins; i++)
    {
        cout << i * 10 << "-" << (i + 1) * 10 - 1 << ": " << histogram[i] << endl;
    }

    return 0;
}

//function to find maximum value 
int findMax(vector<int> myVector)
{
    int max = myVector[0];
    // loop through the remaining elements to find maximum value 
    for (int i = 1; i < myVector.size(); i++)
    {
        if (myVector[i] > max)
        {
            max = myVector[i];
        }
    }
    return max;
}