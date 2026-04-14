//Terry Addey 
//HW 5 Question 4
#include <iostream>
using namespace std;
//based off the code starter professor provided in class
class PrimeNumber {
    private:
    
    int prime;

    bool prime_check(int n){
        
        if (n <= 1)
        {
            return false;
        }
        
        for (int i=2; i*i<=n; i++)
        {
            if (n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    
    int find_next_prime(int n)
    {
        int next_prime = n + 1;
        while (!prime_check(next_prime))
        {
            next_prime++;
        }
        return next_prime;
    }
    
    int find_previous_prime(int n)
    {
        int previous_prime = n - 1;
        while (previous_prime > 1 && !prime_check(previous_prime))
        {
            previous_prime--;
        }
        if (previous_prime > 1)
        {
            return previous_prime;
        }
        else
        {
            return -1; // no previous prime found
        }
    }
    
    public:
    
    PrimeNumber()
    {
        prime = 1; // default to the smallest prime
    }
    PrimeNumber(int p)
    {
        if (prime_check(p))
        {
            prime = p;
        }
        else
        {
            prime = find_next_prime(p);
        }
   
    }
    
    int get_prime_number() const
    {
        return prime;
    }

    void next_prime()
    {
        prime = find_next_prime(prime);
    }
    void previous_prime()
    {
        int prev = find_previous_prime(prime);
        if (prev != -1)
        {
            prime = prev;
        }
        else
        {
            cout << "No previous prime number found." << endl;
        }
    }
    PrimeNumber operator++() // prefix increment
    {
        next_prime();
        return *this;
    }
    PrimeNumber operator++(int) // postfix increment
    {
        PrimeNumber temp = *this;
        next_prime();
        return temp;
    }
    PrimeNumber operator--() // prefix decrement
    {
        previous_prime();
        return *this;
    }
    PrimeNumber operator--(int) // postfix decrement
    {
        PrimeNumber temp = *this;
        previous_prime();
        return temp;
    }
};

int main()
{
    PrimeNumber prime1; // should initialize to the first prime number (2)
    PrimeNumber prime2(10); // should initialize to the next prime number after 10 (11)

    cout << "Initial prime numbers:" << endl;
    cout << "prime1: " << prime1.get_prime_number() << endl;
    cout << "prime2: " << prime2.get_prime_number() << endl;

    ++prime1; // should move to the next prime number (3)
    prime2++; // should move to the next prime number (13)

    cout << "\nAfter incrementing:" << endl;
    cout << "prime1: " << prime1.get_prime_number() << endl;
    cout << "prime2: " << prime2.get_prime_number() << endl;

    --prime1; // should move back to the previous prime number (2)
    prime2--; // should move back to the previous prime number (11)

    cout << "\nAfter decrementing:" << endl;
    cout << "prime1: " << prime1.get_prime_number() << endl;
    cout << "prime2: " << prime2.get_prime_number() << endl;

    return 0;
}