#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int id;
    string firstName;
    string lastName;
    string middleName;
    int age;

public:
    Person();
    Person(int ID, string firstN, string lastN, string middleN, int AGE);
    Person(const Person& s);
    Person& operator=(const Person& s);

    int getId();
    void setId(int ID);

    string getFirstName();
    void setFirstName(string firstN);

    string getLastName();
    void setLastName(string lastN);

    string getMiddleName();
    void setMiddleName(string middleN);

    int getAge();
    void setAge(int a);

    string toString();
};