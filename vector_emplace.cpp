#include <iostream>
#include <vector>
using namespace std;

// Example class to demonstrate emplace
class Person {
public:
    string name;
    int age;

    // Constructor
    Person(const string& name, int age) : name(name), age(age) {
        cout << "Constructing Person: " << name << ", " << age << endl;
    }
};

int main() {
    // Create a vector of Person objects
    vector<Person> people;

    // Use emplace to add elements in-place
    cout << "Adding persons using emplace:\n";
    people.emplace_back("Alice", 25);  // Constructs in-place at the end
    people.emplace_back("Bob", 30);   // Constructs in-place at the end

    // Use emplace to add an element at a specific position
    // cout << "Inserting a person using emplace at position 1:\n";
    // people.emplace(1, "Charlie", 28);  // Inserts at index 1, shifts others

    // Display the vector contents
    cout << "\nList of people:\n";
    for (const auto& person : people) {
        cout << person.name << ", " << person.age << endl;
    }

    return 0;
}