#include <string>
#include <iostream>
#include "BaseFaculty.h"
using namespace std;

BaseFaculty::BaseFaculty() {
	id = NULL;
	math_coef = NULL;
	ukrainian_coef = NULL;
	history_coef = NULL;
}

BaseFaculty::BaseFaculty(int ID, double mathC, double ukrCoef, double histCoef) {
	id = ID;
	math_coef = mathC;
	ukrainian_coef = ukrCoef;
	history_coef = histCoef;
}

BaseFaculty::BaseFaculty(const BaseFaculty& s) {
	id = s.id;
	math_coef = s.math_coef;
	ukrainian_coef = s.ukrainian_coef;
	history_coef = s.history_coef;
}

BaseFaculty& BaseFaculty::operator=(const BaseFaculty& s) {
	id = s.id;
	math_coef = s.math_coef;
	ukrainian_coef = s.ukrainian_coef;
	history_coef = s.history_coef;
	cout << "   BaseFaculty& operator=(const BaseFaculty& s)" << endl;
	return *this;
}

int BaseFaculty::getId() {
	return id;
}
void BaseFaculty::setId(int ID) {
	id = ID;
}

double BaseFaculty::getMathCoef() {
	return math_coef;
}
void BaseFaculty::setMathCoef(double mathCoef) {
	math_coef = mathCoef;
}

double BaseFaculty::getUkrainianCoef() {
	return ukrainian_coef;
}
void BaseFaculty::setUkrainianCoef(double ukrCoef) {
	ukrainian_coef = ukrCoef;
}

double BaseFaculty::getHistoryCoef() {
	return history_coef;
}
void BaseFaculty::setHistoryCoef(double histCoef) {
	history_coef = histCoef;
}

string BaseFaculty::toString() {
	string ID = to_string(id);
	string mathCoef = to_string(math_coef);
	string histCoef = to_string(history_coef);
	string ukrCoef = to_string(ukrainian_coef);

	string result = "\n Math coeficient: " + mathCoef + "\n Ukrainian coeficient: " + ukrCoef
		+ "\n History coeficient: " + histCoef;
	return result;
}
