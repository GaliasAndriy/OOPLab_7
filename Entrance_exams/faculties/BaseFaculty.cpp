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

BaseFaculty::BaseFaculty(int ID, double mathC, double ukrCoef, double histCoef, double threshholdScore) {
	id = ID;
	math_coef = mathC;
	ukrainian_coef = ukrCoef;
	history_coef = histCoef;
	threshold_score = threshholdScore;
}

BaseFaculty::BaseFaculty(const BaseFaculty& s) {
	id = s.id;
	math_coef = s.math_coef;
	ukrainian_coef = s.ukrainian_coef;
	history_coef = s.history_coef;
	threshold_score = s.threshold_score;
}

BaseFaculty& BaseFaculty::operator=(const BaseFaculty& s) {
	id = s.id;
	math_coef = s.math_coef;
	ukrainian_coef = s.ukrainian_coef;
	history_coef = s.history_coef;
	threshold_score = s.threshold_score;
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

double BaseFaculty::getThresholdScore() {
	return threshold_score;
}
void BaseFaculty::setThresholdScore(double thresholdScore) {
	threshold_score = thresholdScore;
}

bool BaseFaculty::operator<(const BaseFaculty& other) const {
	return id < other.id;
}

string BaseFaculty::toString() {
	string ID = to_string(id);
	string mathCoef = to_string(math_coef);
	string histCoef = to_string(history_coef);
	string ukrCoef = to_string(ukrainian_coef);
	string thresholdScore = to_string(threshold_score);

	string result = "\n Math coeficient: " + mathCoef + "\n Ukrainian coeficient: " + ukrCoef
		+ "\n History coeficient: " + histCoef + "\n Threshold score: " + thresholdScore;
	return result;
}
