// Terry Addey
// ECE 205
// Homework 4, Question 3

#include <iostream>
using namespace std;

const int ROWS = 10;
const int COLS = 4;

void initializeSeats(char seats[][COLS]);
void showSeats(char seats[][COLS]);
bool assignSeat(char seats[][COLS], int row, char seatLetter);
bool noSeats(char seats[][COLS]);

int main()
{
    char seats[ROWS][COLS];
    char choice = 'y';

    initializeSeats(seats);

    while (choice == 'y' || choice == 'Y')
    {
        showSeats(seats);

        if (noSeats(seats))
        {
            cout << "You're cooked! All seats are taken." << endl;
            break;
        }

        int row;
        char letter;

        cout << "Enter desired seat (i.e, 3 C): " << endl;
        cin >> row >> letter;

        while (!assignSeat(seats, row, letter))
        {
            cout << "You're cooked! Seat unavailable. Try again: " << endl;
            cin >> row >> letter;
        }

        cout << "Seat Assigned!" << endl;

        cout << "Do you want to assign another seat?: ";
        cin >> choice;
    }

    cout << "Final Seat Chart:";
    showSeats(seats);

    return 0;
}

//  seat letters
void initializeSeats(char seats[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }
}

// display seating chart
void showSeats(char seats[][COLS])
{
    cout << "Seat Chart:" << endl;

    for (int i = 0; i < ROWS; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < COLS; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

// assign a seat
bool assignSeat(char seats[][COLS], int row, char seatLetter)
{
    if (row < 1 || row > ROWS)
        return false;

    int col;

    if (seatLetter == 'A') col = 0;
    else if (seatLetter == 'B') col = 1;
    else if (seatLetter == 'C') col = 2;
    else if (seatLetter == 'D') col = 3;
    else return false;

    if (seats[row - 1][col] == 'X')
        return false;

    seats[row - 1][col] = 'X';
    return true;
}

// check if plane is full
bool noSeats(char seats[][COLS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] != 'X')
                return false;

    return true;
}