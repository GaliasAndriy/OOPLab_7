#include "Lecturer.h"
#include "Person.h"
#include <iostream>
using namespace std;

Lecturer::Lecturer() {
    title = "no data";
    facultyID = NULL;
}

Lecturer& Lecturer::operator=(const Lecturer& s) {
    this->Person::operator=(s);
    title = s.title;
    facultyID = s.facultyID;
    return *this;
}

string Lecturer::getTitle() {
    return title;
}
void Lecturer::setTitle(string titl) {
    title = titl;
}

int Lecturer::getFacultyId() {
    return facultyID;
}
void Lecturer::setFacultyId(int id) {
    facultyID = id;
}

string Lecturer::toString() {
    string facultyId = to_string(facultyID);
    string result = Person::toString() + "\n Title: " + title + "\n Faculty ID: " + facultyId;
    return result;
}

string Lecturer::toStringBaseInfo() {
    string facultyId = to_string(facultyID);
    string result = Person::toString() + "\n Faculty ID: " + facultyId;
    return result;
}