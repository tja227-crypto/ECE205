// Terry Addey
// ECE 205
// Homework 4, Question 1

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;   // maximum number of input values
const int MAX_BINS = 20;    // covers values up to 199

void inputNumbers(int arr[], int size);
int findMax(int arr[], int size);
void calculateHistogram(int arr[], int size, int histogram[], int bins);
void outputHistogram(int histogram[], int bins);

int main()
{
    int size;
    cout << "Enter the number of integers (Max " << MAX_SIZE << "): ";
    cin >> size;
    while (size <= 0 || size > MAX_SIZE)
    {
        cout << "You're cooked! Try again: ";
        cin >> size;
    }
    int arr[MAX_SIZE];           
    int histogram[MAX_BINS] = {0};
    inputNumbers(arr, size);
    int maxValue = findMax(arr, size);
    int bins = (maxValue / 10) + 1;
    if (bins > MAX_BINS)
        bins = MAX_BINS;   
    calculateHistogram(arr, size, histogram, bins);
    outputHistogram(histogram, bins);
    return 0;
}

void inputNumbers(int arr[], int size)
{
    cout << "Enter " << size << " non-negative integers:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        while (arr[i] < 0)
        {
            cout << "You're cooked! Invalid input. Enter a non-negative integer: ";
            cin >> arr[i];
        }
    }
}

int findMax(int arr[], int size)
{
    int maxValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }
    return maxValue;
}

void calculateHistogram(int arr[], int size, int histogram[], int bins)
{
    for (int i = 0; i < size; i++)
    {
        int index = arr[i] / 10;

        if (index < bins)   
            histogram[index]++;
    }
}

void outputHistogram(int histogram[], int bins)
{
    cout << "\nHistogram:\n";
    for (int i = 0; i < bins; i++)
    {
        cout << i * 10 << "-" << (i * 10 + 9)
             << ": " << histogram[i] << endl;
    }
}