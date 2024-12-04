#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Declare an unordered_map to store student names and their grades
    unordered_map<string, char> studentGrades;

    // Insert elements into the unordered_map
    studentGrades["Alice"] = 'A';
    studentGrades["Bob"] = 'B';
    studentGrades["Charlie"] = 'C';

    // Using emplace to add an element
    studentGrades.emplace("David", 'A');

    // Access and modify elements using keys
    cout << "Grade for Alice: " << studentGrades["Alice"] << endl;

    // Check if a key exists
    string keyToFind = "Eve";
    if (studentGrades.find(keyToFind) != studentGrades.end()) {
        cout << keyToFind << " is found with grade: " << studentGrades[keyToFind] << endl;
    } else {
        cout << keyToFind << " is not found in the map." << endl;
    }

    // Iterate through the unordered_map
    cout << "\nAll student grades:\n";
    for (const auto& pair : studentGrades) {
        cout << "Name: " << pair.first << ", Grade: " << pair.second << endl;
    }

    // Remove an element
    cout << "\nRemoving Bob's entry..." << endl;
    studentGrades.erase("Bob");

    // Display remaining elements
    cout << "Remaining students:\n";
    for (const auto& pair : studentGrades) {
        cout << "Name: " << pair.first << ", Grade: " << pair.second << endl;
    }

    return 0;
}