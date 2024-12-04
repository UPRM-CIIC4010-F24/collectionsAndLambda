#include <iostream>
#include <array>  // Required for std::array
using namespace std;

int main() {
    // Declare and initialize an std::array of fixed size
    array<int, 5> arr = {1, 2, 3, 4, 5};

    // Accessing elements using indexing
    cout << "Elements in the array: ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Accessing elements using a range-based for loop
    cout << "Elements (using range-based for loop): ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Modifying elements
    arr[0] = 10;
    cout << "After modifying the first element: ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Accessing specific elements using at()
    cout << "Third element using at(): " << arr.at(2) << endl;

    // Using front() and back()
    cout << "First element (front): " << arr.front() << endl;
    cout << "Last element (back): " << arr.back() << endl;

    // Filling the array with a specific value
    arr.fill(7);
    cout << "After filling with 7: ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Accessing array size
    cout << "Size of the array: " << arr.size() << endl;

    // Swapping two arrays
    array<int, 5> anotherArr = {8, 9, 10, 11, 12};
    cout << "Another array before swapping: ";
    for (const int& num : anotherArr) {
        cout << num << " ";
    }
    cout << endl;

    arr.swap(anotherArr);

    cout << "Array after swapping: ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Another array after swapping: ";
    for (const int& num : anotherArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}