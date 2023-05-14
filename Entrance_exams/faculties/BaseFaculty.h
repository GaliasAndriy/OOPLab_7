#pragma once
#include <string>
#include <iostream>
using namespace std;

class BaseFaculty {
private: 
	int id;
	double math_coef;
	double ukrainian_coef;
	double history_coef;
	double threshold_score;
public:
	BaseFaculty();
	BaseFaculty(int id, double math_coef, double ukrainian_coef, double history_coef, double threshold_score);
	BaseFaculty(const BaseFaculty& s);
	BaseFaculty& operator=(const BaseFaculty& s);

	int getId();
	void setId(int ID);

	double getMathCoef();
	void setMathCoef(double mathCoef);

	double getUkrainianCoef();
	void setUkrainianCoef(double ukrainianCoef);

	double getHistoryCoef();
	void setHistoryCoef(double historyCoef);

	double getThresholdScore();
	void setThresholdScore(double thresholdScore);

	bool operator<(const BaseFaculty& other) const;

	string toString();
};