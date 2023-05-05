#include "Applicant.h"
#include "Person.h"
#include <iostream>
using namespace std;

Applicant::Applicant() {
    phone_number = "no data";
    email = "no data";
    passport = "no data";
}

Applicant& Applicant::operator=(const Applicant& s) {
    this->Person::operator=(s);
    phone_number = s.phone_number;
    email = s.email;
    passport = s.passport;
    return *this;
}

string Applicant::getPhoneNumber() {
    return phone_number;
}
void Applicant::setPhoneNumber(string phoneN) {
    phone_number = phoneN;
}

string Applicant::getEmail() {
    return email;
}
void Applicant::setEmail(string e) {
    email = e;
}

string Applicant::getPassport() {
    return passport;
}
void Applicant::setPassport(string pass) {
    passport = pass;
}

string Applicant::toString() {
    string result = Person::toString() + "\n Phone number: " + phone_number + "\n Email: " + email
        + "\n Passport: " + passport + "\n";
    return result;
}