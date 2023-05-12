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
#include "middleware/WriteNewLecturerToFile.h"
#include "middleware/newLecturerForFaculty.h"
using namespace std;

int main() {
    cout << "Testing applicants" << endl;
    srand(time(nullptr));

    // Getting list of all the applicants
    string fileName = "database/applicants.txt";
    vector<Applicant> applicants = readFile(fileName);

    cout << "\nAll valid Applicant objects:" << endl;
    cout << "------------------------------------------------------" << endl;
    for (auto& person : applicants) {
        cout << person.toString() << endl;
    }
    cout << "------------------------------------------------------" << endl;

    // Then we need to choose an applicant by their ID
    cout << "\nChoose an applicant from the previous list: " << endl;
    int userID;
    bool validID = false;
    bool foundApplicant = false;
    do {
        cout << "  Enter applicant ID: ";
        try {
            // Check if client entered valid ID
            cin >> userID;
            if (cin.fail()) {
                throw runtime_error("Invalid input: not an integer");
            }
            validID = true;

            // Then search for a user
            for (auto& applicant : applicants) {
                if (applicant.getId() == userID) {
                    foundApplicant = true;
                    // Output founded user 
                    cout << "\nApplicant information: " << endl;
                    cout << "--------------------------------------" << endl;
                    cout << applicant.toString();
                    cout << "--------------------------------------" << endl;
                    break;
                }
            }
            if (!foundApplicant) {
                throw runtime_error("Applicant with such ID does not exist! Enter again.");
            }
        }
        catch (runtime_error& e) {
            cerr << e.what() << endl;
            cin.clear();  // Clear the error flag on the input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validID || !foundApplicant);
    validID = false;

    // After that, we should output a list of faculties and applicant be able to choose one of them
    string facultyFile = "database/faculties.txt";
    vector<Faculty> faculties = readFacultyFile(facultyFile);

    cout << "\nList of faculties:" << endl;
    cout << "------------------------------------------------------";
    for (auto& faculty : faculties) {
        cout << faculty.toString();
    }
    cout << "------------------------------------------------------";

    // Here's a list of faculties and applicant may choose one of them
    cout << "\nChoose the faculty from the previous list: " << endl;
    int facultyID;
    string facultyName;
    bool validFacultyID = false;
    bool foundFaculty = false;
    do {
        cout << "  Enter the faculty ID: ";
        try {
            cin >> facultyID;
            if (cin.fail()) {
                throw runtime_error("Invalid input: not an integer");
            }
            validFacultyID = true;

            // Then search for a faculty
            for (auto& faculty : faculties) {
                if (faculty.getId() == facultyID) {
                    foundFaculty = true;
                    facultyName = faculty.getSpecialty();
                    // Output founded faculty 
                    cout << "\nFaculty information: " << endl;
                    cout << "--------------------------------------";
                    cout << faculty.toString();
                    cout << "--------------------------------------" << endl;
                    break;
                }
            }
            if (!foundFaculty) {
                throw runtime_error("Faculty with such ID does not exist! Enter again.");
            }
        }
        catch (runtime_error& e) {
            cerr << e.what() << endl;
            cin.clear();  // Clear the error flag on the input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validFacultyID || !foundFaculty);

    // For choosen facultyID, we're going to show the list of lecturers that belongs to the faculty
    string lecturerFile = "database/lecturers.txt";
    vector<Lecturer> lecturers = readLecturerFile(lecturerFile);

    vector<Lecturer> sortedLecturers;
    cout << "\nList of lecturers that belongs to " << facultyName << " faculty" << endl;
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
    if (sortedLecturers.size() > 0) {
        int index = rand() % sortedLecturers.size();  // generate a random index
        Lecturer chosenLecturer = sortedLecturers[index];
        cout << "\nChosen lecturer: " << endl;
        cout << chosenLecturer.toString() << endl;
    }
    // Create one more lecturers which belongs to specific faculty
    else {
        int lecturerID = createNewLecturer(facultyID);
        for (auto& lect : lecturers) {
            if (lect.getId() == lecturerID) {
                cout << "\n Created and choosen lecturer: " << endl;
                cout << lect.toString() << endl;
            }
        }
    }

    // Create new exam with generated id
    Exam newExam;
    // Here we should provide a marks for each subject
    // Than we should calculate final mark including coeficients
    // After that we'll compare total mark with threshold score
    // In case if total_mark > threshold_score, we'll open a file with approved applicants, push them all
    // Into container, check max ID and generate a new one previously added + 1 to max ID value.
    // Otherwise we'll do the same, but with rejected_appliacants file.
    // As a result, we'll decide rather applicant was approved or rejected
    // 
    // If all my previous implementation is correct, we'll have a proper Ids from all vectors, 
    // we can just put all the information on the table with all provided information
    // Finally, we'll save our result in files for approved/rejected exams
    // 

    // All this implementation will be inside a simple do while cycle, with simple menu
    // Also, it would be nice to make more clear file structure in this project.





    /*cout << "\nEnter next info about an exam:" << endl;
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
    cout << newExam.toString() << endl;*/

    return 0;
}