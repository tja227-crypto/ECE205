// Terry Addey
// ECE 205
// Homework 4, Question 2

#include <iostream>
using namespace std;

const int JUDGES = 7;

double getDifficulty();
void getScores(double scores[]);
double findHighest(double scores[]);
double findLowest(double scores[]);
double calculateFinalScore(double scores[], double difficulty);

int main()
{
    double scores[JUDGES];
    double difficulty;

    difficulty = getDifficulty();

    getScores(scores);

    double finalScore = calculateFinalScore(scores, difficulty);

    cout << "\nFinal Diver Score: " << finalScore << endl;

    return 0;
}

// Get and validate difficulty
double getDifficulty()
{
    double difficulty;

    cout << "Enter degree of difficulty (1.2 - 3.8): ";
    cin >> difficulty;
    while (difficulty < 1.2 || difficulty > 3.8)
    {
        cout << "Out of Bounds! ";
        cin >> difficulty;
    }
    return difficulty;
}

// Get and validate judge scores
void getScores(double scores[])
{
    cout << "Enter 7 judge scores (0 - 10):";
    for (int i = 0; i < JUDGES; i++)
    {
        cin >> scores[i];
        while (scores[i] < 0 || scores[i] > 10)
        {
            cout << "Invalid score. Enter between 0 and 10: ";
            cin >> scores[i];
        }
    }
}
   
//  highest score
double findHighest(double scores[])
{
    double highest = scores[0];
    for (int i = 1; i < JUDGES; i++)
    {
        if (scores[i] > highest)
            highest = scores[i];
    }
    return highest;
}

//  lowest score
double findLowest(double scores[])
{
    double lowest = scores[0];
    for (int i = 1; i < JUDGES; i++)
    {
        if (scores[i] < lowest)
            lowest = scores[i];
    }
    return lowest;
}

// final score
double calculateFinalScore(double scores[], double difficulty)
{
    double highest = findHighest(scores);
    double lowest = findLowest(scores);
    double sum = 0;
    for (int i = 0; i < JUDGES; i++)
        sum += scores[i];
    sum = sum - highest - lowest;
    double finalScore = sum * difficulty * 0.6;
    return finalScore;
}