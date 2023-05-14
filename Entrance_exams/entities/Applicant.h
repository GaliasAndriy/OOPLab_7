#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Applicant : public Person {
private:
	string phone_number;
	string email;
	string passport;

public:
	Applicant();
	Applicant(int id, string firstN, string lastN, string middleN, int AGE, string phoneN,
		string Email, string passp) : Person(id, firstN, lastN, middleN, AGE) {
		phone_number = phoneN;
		email = Email;
		passport = passp;
	}
	Applicant(int id, string firstN, string lastN, string middleN, int AGE) 
		: Person(id, firstN, lastN, middleN, AGE) {}

	Applicant(const Applicant& s) : Person(s) {
		phone_number = s.phone_number;
		email = s.email;
		passport = s.passport;
	}
	Applicant& operator=(const Applicant& s);

	string getPhoneNumber();
	void setPhoneNumber(string phone_number);

	string getEmail();
	void setEmail(string email);

	string getPassport();
	void setPassport(string passport);

	string toString();
};