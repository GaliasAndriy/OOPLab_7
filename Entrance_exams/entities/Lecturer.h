#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Lecturer : public Person {
private:
	string title;
	// Here we should add ID of university, in which the lecturer teaches. It would be a connection between faculies and their lecturers. 
	// Each Faculty will be as main entity and lecturers belong to Faculty
public:
	Lecturer();
	Lecturer(int id, string firstN, string lastN, string middleN, int AGE, string titl)
		: Person(id, firstN, lastN, middleN, AGE) {
		title = titl;
	}

	Lecturer(const Lecturer& s) : Person(s) {
		title = s.title;
	}
	Lecturer& operator=(const Lecturer& s);

	string getTitle();
	void setTitle(string title);

	string toString();
};

