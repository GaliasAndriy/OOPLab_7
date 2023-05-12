#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {
    id = NULL;
    firstName = "no data";
    lastName = "no data";
    middleName = "no data";
    age = NULL;
}

Person::Person(int ID, string firstN, string lastN, string middleN, int AGE) {
    id = ID;
    firstName = firstN;
    lastName = lastN;
    middleName = middleN;
    age = AGE;
}

Person::Person(const Person& s) {
    id = s.id;
    firstName = s.firstName;
    lastName = s.lastName;
    middleName = s.middleName;
    age = s.age;
}

Person& Person::operator=(const Person& s) {
    id = s.id;
    firstName = s.firstName;
    lastName = s.lastName;
    middleName = s.middleName;
    age = s.age;
    return *this;
}

int Person::getId() {
    return id;
}
void Person::setId(int ID) {
    id = ID;
}

string Person::getFirstName() {
    return firstName;
}
void Person::setFirstName(string firstN) {
    firstName = firstN;
}

string Person::getLastName() {
    return lastName;
}
void Person::setLastName(string lastN) {
    lastName = lastN;
}

string Person::getMiddleName() {
    return middleName;
}
void Person::setMiddleName(string middleN) {
    middleName = middleN;
}

int Person::getAge() {
    return age;
}
void Person::setAge(int a) {
    age = a;
}

bool Person::operator<(const Person& other) const {
    return id < other.id;
}

string Person::toString() {
    string ID = to_string(id);
    string AGE = to_string(age);
    cout << " ID: ";
    string result = "\033[34;1m" + ID + "\033[0m" + "\n Full name: " + firstName + " " + middleName + " " + lastName + "\n Age: " + AGE;
    return result;
}