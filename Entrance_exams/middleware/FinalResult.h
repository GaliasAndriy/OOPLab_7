#pragma once
#include <iostream>
#include <string>
#include "../entities/Exam.h"
#include "../entities/Applicant.h"
#include "../entities/Lecturer.h"
#include "../entities/Person.h"

using namespace std;

class FinalResult {
private:
    Applicant applicant;
    Exam exam;
    Lecturer lecturer;
public:
    FinalResult(int applicant_id, string applicant_firstN, string applicant_lastN, string applicant_middleN, int applicant_age,
        int exam_id, double math_mark, double ukr_mark, double history_mark, double exam_grade,
        int lecturer_id, string lecturer_firstN, string lecturer_lastN, string lecturer_middleN, int lecturer_age, int facultyID)
        : applicant(applicant_id, applicant_firstN, applicant_lastN, applicant_middleN, applicant_age),
        exam(exam_id, math_mark, ukr_mark, history_mark, exam_grade),
        lecturer(lecturer_id, lecturer_firstN, lecturer_lastN, lecturer_middleN, lecturer_age, facultyID) {}

    Exam& getExam() { return exam; }
    Lecturer& getLecturer() { return lecturer; }
    Applicant& getPerson() { return applicant; }

    int getExamId() {
        return exam.getExamId();
    }

    string toString() {
        string result = "\n" + applicant.toString() + "\n" + exam.toString() + "\n" + lecturer.toStringBaseInfo() + "\n";
        return result;
    }
};