#include <iostream>
#include <string>

int main() {
    // Print a simple string
    std::cout << "Hello, World!"; 

    // Print a string and a variable in the same line
    int number = 10;
    std::cout << "The number is: " << number;

    // Add a new line using `std::endl` or the escape sequence `\n`
    std::cout << "This is on one line." << std::endl; // std::endl adds a new line and flushes the buffer
    std::cout << "This is on a new line using \\n." << "\n"; // '\n' is often faster
    
    return 0;
}


