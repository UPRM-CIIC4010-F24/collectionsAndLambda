#include <iostream>
using namespace std;

// A simple function
void greet() {
    cout << "Hello, Function Pointer!" << endl;
}

// A function that accepts a function pointer
void execute(void (*funcPtr)()) {
    cout << "Executing function..." << endl;
    funcPtr();  // Call the function via the pointer
}

int main() {
    // Declare a function pointer and assign it to a function
    void (*funcPtr)() = greet;

    // Call the function using the pointer
    funcPtr();

    // Pass the function pointer to another function
    execute(funcPtr);

    return 0;
}