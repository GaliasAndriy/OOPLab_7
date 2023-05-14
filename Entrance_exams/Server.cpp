#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <thread>
using namespace std;

#include "Server.h"
#include "entities/Applicant.h"
#include "middleware/ReadApplicantsFile.h"
#include "faculties/Faculty.h"
#include "middleware/ReadFacultyFile.h"
#include "middleware/ReadLecturersFile.h"
#include "middleware/ChooseObject.h"
#include "middleware/newLecturerForFaculty.h"
#include "middleware/CreateNewExam.h"
#include "middleware/WriteExamResultToFiles.h"

vector<Applicant> Server::showApplicantList() {
    // Getting list of all the applicants
    string fileName = "database/applicants.txt";
    vector<Applicant> applicants = readFile(fileName);

    // Sort applicants
    sort(applicants.begin(), applicants.end(),
        [](const Applicant& a, const Applicant& b) { return a < b; });
    cout << "\nAll valid Applicant objects:" << endl;
    cout << "------------------------------------------------------" << endl;
    for (auto& person : applicants) {
        cout << person.toString() << endl;
        cout << endl;
    }
    cout << "------------------------------------------------------" << endl;

    return applicants;
}

vector<Faculty> Server::showFacultyList() {
    string facultyFile = "database/faculties.txt";
    vector<Faculty> faculties = readFacultyFile(facultyFile);
    // Sort faculties
    sort(faculties.begin(), faculties.end(),
        [](const Faculty& a, const Faculty& b) { return a < b; });
    cout << "\nList of faculties:" << endl;
    cout << "------------------------------------------------------";
    for (auto& faculty : faculties) {
        cout << faculty.toString();
    }
    cout << "------------------------------------------------------";

    return faculties;
}

void Server::showLecturerList() {
    string lecturerFile = "database/lecturers.txt";
    vector<Lecturer> lecturers = readLecturerFile(lecturerFile);
    vector<Lecturer> sortedLecturers;
    cout << "------------------------------------------------------" << endl;
    for (auto& lecturer : lecturers) {
        sortedLecturers.push_back(lecturer);
    }

    // Sort lecturers
    sort(sortedLecturers.begin(), sortedLecturers.end(),
        [](const Lecturer& a, const Lecturer& b) { return a < b; });
    for (auto& lecturer : sortedLecturers) {
        cout << lecturer.toString() << endl;
        cout << endl;
    }
    cout << "------------------------------------------------------";
}

void Server::findApplicantByName() {
    string fileName = "database/applicants.txt";
    vector<Applicant> applicants = readFile(fileName);

    string firstName, lastName;
    cout << " Enter first name: ";
    cin >> firstName;
    cout << " Enter last name: ";
    cin >> lastName;
    firstName = trim(firstName);
    lastName = trim(lastName);

    cout << "------------------------------------------------------" << endl;
    for (auto& person : applicants) {
        if (person.getFirstName() == firstName && person.getLastName() == lastName) {
            cout << person.toString() << endl;
        }
    }
    cout << "------------------------------------------------------" << endl;
}

void Server::findFacultyById() {
    string facultyFile = "database/faculties.txt";
    vector<Faculty> faculties = readFacultyFile(facultyFile);
    
    int facultyID;
    bool validInput = false;
    do {
        try {
            cout << "\n Enter faculty ID: ";
            cin >> facultyID;

            if (cin.fail()) {
                throw runtime_error("Invalid input! Please enter a valid integer value.");
            }

            validInput = true;
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    } while (!validInput);

    cout << "------------------------------------------------------";
    for (auto& faculty : faculties) {
        if (faculty.getId() == facultyID) {
            cout << faculty.toString();
        }
    }
    cout << "------------------------------------------------------";
}

void Server::creatNewExam() {
    // Call applicant list
    vector<Applicant> applicants = showApplicantList(); 

    // Choose applicant from list
    cout << "\nChoose an applicant from previous list: " << endl;
    int userID = chooseApplicant(applicants);

    // Show list of faculties
    vector<Faculty> faculties = showFacultyList();
    cout << "\nChoose the faculty from previous list: " << endl;
    int facultyID = chooseFaculty(faculties);
    string facultyName;
    for (auto& faculty : faculties) {
        if (faculty.getId() == facultyID) {
            facultyName = faculty.getSpecialty();
        }
    }

    // For choosen facultyID, we're going to show the list of lecturers that belongs to the faculty
    string lecturerFile = "database/lecturers.txt";
    vector<Lecturer> lecturers = readLecturerFile(lecturerFile);
    vector<Lecturer> sortedLecturers;
    cout << "\nList of lecturers that belongs to " << facultyName << endl;
    cout << "--------------------------------------" << endl;
    for (auto& lecturer : lecturers) {
        if (lecturer.getFacultyId() == facultyID) {
            sortedLecturers.push_back(lecturer);
        }
    }
    // Sort lecturers
    sort(sortedLecturers.begin(), sortedLecturers.end(),
        [](const Lecturer& a, const Lecturer& b) { return a < b; });
    for (auto& lecturer : sortedLecturers) {
        cout << lecturer.toString() << endl;
        cout << endl;
    }
    cout << "--------------------------------------" << endl;

    // Randomly pick a lecturer
    int chosenLecturerId = 0;
    if (sortedLecturers.size() > 0) {
        int index = rand() % sortedLecturers.size();  // generate a random index
        Lecturer chosenLecturer = sortedLecturers[index];
        cout << "\nChosen lecturer: " << endl;
        cout << chosenLecturer.toString() << endl;
        chosenLecturerId = chosenLecturer.getId();
    }
    // Create one more lecturers which belongs to specific faculty
    else {
        chosenLecturerId = createNewLecturer(facultyID);
        for (auto& lect : lecturers) {
            if (lect.getId() == chosenLecturerId) {
                cout << "\n Created and choosen lecturer: " << endl;
                cout << lect.toString() << endl;
            }
        }
    }

    // Create new exam with generated id
    Exam newExam = generateExam();
    double exam_grade = 0;
    bool isPassed = false;
    for (auto& faculty : faculties) {
        if (faculty.getId() == facultyID) {
            exam_grade = faculty.getMathCoef() * newExam.getMathMark() + faculty.getUkrainianCoef() * newExam.getUkrMark()
                + faculty.getHistoryCoef() * newExam.getHistorymark();
        }
        newExam.setExamGrade(exam_grade);
        if (faculty.getThresholdScore() <= exam_grade) {
            isPassed = true;
        }
    }

    // Imitating of request
    cout << "Processing request ";
    cout.flush(); // flush the output buffer to ensure message is printed immediately
    for (int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << ".";
        cout.flush();
    }
    cout << endl;

    // Then we should open a proper file, based on isPassed flag and set id.
    bool resultSuccess = showResultToClient(isPassed, newExam, applicants, userID, lecturers, chosenLecturerId);

    if (resultSuccess) {
        cout << "\n Congratulations! You're successfully passed the entrance exams!" << endl;
    }
    else {
        cout << "\n We're sorry, You'are not passed the entrance exams! Work harder." << endl;
    }
}

std::string Server::trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }
    auto end = str.end();
    while (end != start && std::isspace(*(end - 1))) {
        end--;
    }
    return string(start, end);
}