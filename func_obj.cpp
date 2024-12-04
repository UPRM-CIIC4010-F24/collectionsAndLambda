#include <iostream>
using namespace std;

// Define a function object (functor)
class Multiply {
private:
    int factor;
public:
    Multiply(int f) : factor(f) {}

    // Overload operator() to make the object callable
    int operator()(int x) const {
        return x * factor;
    }
};

int main() {
    // Create a functor with a factor of 3
    Multiply multiplyBy3(3);

    // Use the functor as a function
    cout << "3 * 5 = " << multiplyBy3(5) << endl;

    // Use the functor in a standard algorithm (e.g., transform)
    cout << "Using functor with a for loop: ";
    for (int i = 1; i <= 5; i++) {
        cout << multiplyBy3(i) << " ";
    }
    cout << endl;

    return 0;
}