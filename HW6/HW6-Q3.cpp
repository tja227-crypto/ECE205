//Terry Addey 
//HW 6 Question 3

#include <iostream>
using namespace std;
#include <vector>
//started using professors starter code 

// function prototype
void SieveOfEratosthenes(int n);

int main() 
{
  int n;
  cout << "Enter a number to see the primes lower than it: "; //get user input 
  cin >> n;
	cout << endl;
  SieveOfEratosthenes(n); //call function to find primes less than n 
    return 0;
}

void SieveOfEratosthenes(int n) // function to find prime numbers less than n 
{
  vector<bool> primes(n, true); // vector to keep track of the prime numbers 
	primes[0] = primes[1] = false; // 0 and 1 are not prime numbers 
   
    // loop through the numbers starting at 2 
    for (int i = 2; i * i < n; i++) 
    
  {
    if (primes[i]) 
    {
      for (int j = i * i; j < n; j += i) 
      {
        primes[j] = false;
      }
    }

  }
    cout << "Prime numbers less than " << n << ": ";
    // print the prime numbers
    for (int i = 2; i < n; i++)
    {
        if (primes[i]) 
        {
            cout << i << " ";
        }
    }
    cout << endl;

}