#include <iostream>
#include <vector>
#include <algorithm>  // For count_if and sort
using namespace std;
class Person {
public:
    string name;
    int age;

    // Constructor
    Person(const string& name, int age) : name(name), age(age) {};

    int getAge() {
        return age;
    }
    string getName() {
        return name;
    }
};

void countIfExample() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Count numbers greater than 5 using a lambda
    int count = count_if(numbers.begin(), numbers.end(), [](int x) {
        return x > 5;  // Predicate: true if x > 5
    });

    cout << "Count of numbers greater than 5: " << count << endl;

    // Count even numbers using another lambda
    count = count_if(numbers.begin(), numbers.end(), [](int x) {
        return x % 2 == 0;  // Predicate: true if x is even
    });

    cout << "Count of even numbers: " << count << endl;

}

void forEachExample() {


    // A lambda expression to filter elements in a vector
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    // Use the lambda with std::for_each
    cout << "Numbers greater than 3: ";
    for_each(nums.begin(), nums.end(), [](int num) {
        if (num > 3) {
            cout << num << " ";
        }
    });
    cout << endl;


}
void sortExample() {
    vector<int> numbers = {5, 3, 8, 6, 2, 7, 4, 1, 9};

    // Sort in ascending order using a lambda
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;  // Comparison: true if a should come before b
    });

    cout << "Numbers sorted in ascending order: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    // Sort in descending order using another lambda
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;  // Comparison: true if a should come after b
    });

    cout << "Numbers sorted in descending order: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

}
void sortExampleObjects() {
    vector<Person> people {
        Person("Alice", 27),
        Person("Ben", 69),
        Person("Charles", 93),
        Person("Drake", 46),
        Person("Nigel", 23),
        Person("James", 13)
    };

    // Sort in ascending order by age
    sort(people.begin(), people.end(), [](Person a, Person b) {
        return a.getAge() < b.getAge();  // Comparison: true if a should come before b
    });

    cout << "People sorted in ascending order of age: ";
    for (Person n : people) {
        cout << n.getName() << " ";
    }
    cout << endl;

}

int main() {
            // A lambda expression that adds two numbers
    auto add = [](int a, int b) {
        return a + b;
    };
        // Lambda capturing local variables
    int factor = 2;
    auto multiply = [factor](int x) {
        return x * factor;
    };

    cout << "5 * 2 = " << multiply(5) << endl;

    cout << "10 + 20 = " << add(10, 20) << endl;
    // countIfExample();
    // forEachExample();
    // sortExample();
    sortExampleObjects();

    return 0;
}