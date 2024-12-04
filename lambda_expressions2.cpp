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
vector<Person *> getPersonGreaterThanAge(vector<Person*> people, int age) {
    vector<Person*> result;
    for(Person* p: people) {
        if(p->getAge() > age)
            result.push_back(p);
    }
    return result;
}

vector<Person *> getPersonGreaterThanName(vector<Person*> people, string name) {
    vector<Person*> result;
    for(Person* p: people) {
        if(p->getName() > name)
            result.push_back(p);
    }
    return result;
}
/*
    This method receives a function. The parameter
    indicates it's a function with (*func) and must specify the 
    parameter type it expects to receive.
*/
template <typename T>
vector<Person*> getPersonGreaterThan(vector<Person*> people, T valToComp, bool (*func)(Person*, T val)) {
    vector<Person*> result;
    for(Person* p: people) {
        if(func(p, valToComp))
            result.push_back(p);
    }
    return result;
}

int main() {
    vector<Person*> people {
        new Person("Alice", 27),
        new Person("Ben", 69),
        new Person("Charles", 93),
        new Person("Drake", 46),
        new Person("Nigel", 23),
        new Person("James", 13)
    };

    vector<Person*> olderThan40 = getPersonGreaterThanAge(people, 40);
    vector<Person*> namesGreaterThanDrake = getPersonGreaterThanName(people, "Drake");

    cout << "People older than 40" << endl;
    for(Person* p: olderThan40) 
        cout << p->getName() << " ";
    cout << endl;
    
    cout << "People whose name goes after Drake" << endl;
    for(Person* p: namesGreaterThanDrake) 
        cout << p->getName() << " ";
    cout << endl;

    // Doing it with lambdas instead
    auto greaterThanAgeFunc = [] (Person* person, int age) {
        return person->getAge() > age;
    };
    auto greaterThanNameFunc = [] (Person* person, string name) {
        return person->getName() > name;
    };

    olderThan40 = getPersonGreaterThan<int>(people, 40, greaterThanAgeFunc);
    namesGreaterThanDrake = getPersonGreaterThan<string>(people, "Drake", greaterThanNameFunc);

    cout << "================" << endl;
    cout<< "Using lambdas"<< endl;
    cout << "People older than 50" << endl;
    for(Person* p: olderThan40) 
        cout << p->getName() << " ";
    cout << endl;
    
    cout << "People whose name goes after Drake" << endl;
    for(Person* p: namesGreaterThanDrake) 
        cout << p->getName() << " ";
    cout << endl;
    return 0;
}