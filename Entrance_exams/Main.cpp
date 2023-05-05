#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "entities/Applicant.h"
#include "entities/Lecturer.h"
#include "faculties/Faculty.h"
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

    return 0;
}
