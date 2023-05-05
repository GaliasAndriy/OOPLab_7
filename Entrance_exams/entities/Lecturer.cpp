#include "Lecturer.h"
#include "Person.h"
#include <iostream>
using namespace std;

Lecturer::Lecturer() {
    title = "no data";
}

Lecturer& Lecturer::operator=(const Lecturer& s) {
    this->Person::operator=(s);
    title = s.title;
    return *this;
}

string Lecturer::getTitle() {
    return title;
}
void Lecturer::setTitle(string titl) {
    title = titl;
}

string Lecturer::toString() {
    string result = Person::toString() + "\n Title: " + title;
    return result;
}