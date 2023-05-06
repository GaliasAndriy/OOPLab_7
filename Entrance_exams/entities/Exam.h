#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
	int exam_id;
	double math_mark;
	double ukr_mark;
	double history_mark;
	double exam_grade; // Each subject mltp on proper coef and add this 3 marks 
public:
	Exam();
	Exam(int exam_id, double math_mark, double ukr_mark, double history_mark, double exam_grade);
	Exam(const Exam& s);
	Exam& operator=(const Exam& s);

	int getExamId();
	void setExamId(int ID);

	double getMathMark();
	void setMathMark(double math_mark);

	double getUkrMark();
	void setUkrMark(double ukr_mark);

	double getHistorymark();
	void setHistoryMark(double history_mark);

	double getExamGrade();
	void setExamGrade(double exam_grade);

	string toString();
};