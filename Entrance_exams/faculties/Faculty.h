#pragma once
#include <iostream>
#include <string>
#include "BaseFaculty.h"
using namespace std;

class Faculty : public BaseFaculty {
private:
	string specialty;

public:
	Faculty();
	Faculty(int id, double mathCoef, double ukrCoef, double histCoef, string spec)
		: BaseFaculty(id, mathCoef, ukrCoef, histCoef) {
		specialty = spec;
	}

	Faculty(const Faculty& s) : BaseFaculty(s) {
		specialty = s.specialty;
	}
	Faculty& operator=(const Faculty& s);
	
	string getSpecialty();
	void setSpecialty(string specialty);

	string toString();
};