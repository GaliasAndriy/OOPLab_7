#include <string>
#include <iostream>
#include "Exam.h"
using namespace std;

Exam::Exam() {
	exam_id = NULL;
	math_mark = NULL;
	ukr_mark = NULL;
	history_mark = NULL;
	exam_grade = NULL;
}

Exam::Exam(int ID, double mathMark, double ukrMark, double histMark, double examGrade) {
	exam_id = ID;
	math_mark = mathMark;
	ukr_mark = ukrMark;
	history_mark = histMark;
	exam_grade = examGrade;
}

Exam::Exam(const Exam& s) {
	exam_id = s.exam_id;
	math_mark = s.math_mark;
	ukr_mark = s.ukr_mark;
	history_mark = s.history_mark;
	exam_grade = s.exam_grade;
}

Exam& Exam::operator=(const Exam& s) {
	exam_id = s.exam_id;
	math_mark = s.math_mark;
	ukr_mark = s.ukr_mark;
	history_mark = s.history_mark;
	exam_grade = s.exam_grade;
	cout << "   Exam& operator=(const Exam& s)" << endl;
	return *this;
}

int Exam::getExamId() {
	return exam_id;
}
void Exam::setExamId(int ID) {
	exam_id = ID;
}

double Exam::getMathMark() {
	return math_mark;
}
void Exam::setMathMark(double mathM) {
	math_mark = mathM;
}

double Exam::getUkrMark() {
	return ukr_mark;
}
void Exam::setUkrMark(double ukrMark) {
	ukr_mark = ukrMark;
}

double Exam::getHistorymark() {
	return history_mark;
}
void Exam::setHistoryMark(double histMark) {
	history_mark = histMark;
}

double Exam::getExamGrade() {
	return exam_grade;
}
void Exam::setExamGrade(double examGr) {
	exam_grade = examGr;
}

string Exam::toString() {
	string examID = to_string(exam_id);
	string mathMark = to_string(math_mark);
	string ukrMark = to_string(ukr_mark);
	string histMark = to_string(history_mark);
	string examGrade = to_string(exam_grade);

	string result = "\n Exam ID: " + examID + "\n Math mark: " + mathMark + "\n Ukrainian language mark: " + ukrMark
		+ "\n History mark: " + histMark + "\n Exam grade: " + "\033[32m" + examGrade + "\033[0m";
	return result;
}

