#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "entities/Applicant.h"
#include "entities/Lecturer.h"
#include "faculties/Faculty.h"
#include "entities/Exam.h"
#include "middleware/ReadApplicantsFile.h"
#include "middleware/ReadLecturersFile.h"
#include "middleware/ReadFacultyFile.h"
using namespace std;

int main() {
    cout << "Testing applicants" << endl;

    string fileName = "database/applicants.txt";
    vector<Applicant> applicants = readFile(fileName);

    cout << "\nAll valid Applicant objects:" << endl;
    cout << "------------------------------------------------------" << endl;
    for (auto& person : applicants) {
        cout << person.toString() << endl;
    }

    string lecturerFile = "database/lecturers.txt";
    vector<Lecturer> lecturers = readLecturerFile(lecturerFile);

    cout << "\nAll valid Lecturer objects:" << endl;
    cout << "------------------------------------------------------" << endl;
    for (auto& person : lecturers) {
        cout << person.toString() << endl;
    }

    string facultyFile = "database/faculties.txt";
    vector<Faculty> faculties = readFacultyFile(facultyFile);

    cout << "\nAll valid faculties objects:" << endl;
    cout << "------------------------------------------------------" << endl;
    for (auto& faculty : faculties) {
        cout << faculty.toString() << endl;
    }

    cout << "\nEnter next info about an exam:" << endl;
    Exam newExam;
    int examID;
    double math_mark, ukr_mark, hist_mark, exam_grade;
    cout << " Exam ID: "; cin >> examID;
    cout << " Math mark: "; cin >> math_mark;
    cout << " Ukr mark: "; cin >> ukr_mark;
    cout << " Hist mark: "; cin >> hist_mark;
    cout << " Exam grade: "; cin >> exam_grade;

    newExam.setExamId(examID);
    newExam.setMathMark(math_mark);
    newExam.setUkrMark(ukr_mark);
    newExam.setHistoryMark(hist_mark);
    newExam.setExamGrade(exam_grade);
    cout << newExam.toString() << endl;

    return 0;
}
