#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Lecturer : public Person {
private:
	string title;
	int facultyID;
public:
	Lecturer();
	Lecturer(int id, string firstN, string lastN, string middleN, int AGE, string titl, int fID)
		: Person(id, firstN, lastN, middleN, AGE) {
		title = titl;
		facultyID = fID;
	}
	Lecturer(int id, string firstN, string lastN, string middleN, int AGE, int fID)
		: Person(id, firstN, lastN, middleN, AGE) {
		facultyID = fID;
	}

	Lecturer(const Lecturer& s) : Person(s) {
		title = s.title;
		facultyID = s.facultyID;
	}
	Lecturer& operator=(const Lecturer& s);

	string getTitle();
	void setTitle(string title);

	int getFacultyId();
	void setFacultyId(int id);

	string toString();
	string toStringBaseInfo();
};

