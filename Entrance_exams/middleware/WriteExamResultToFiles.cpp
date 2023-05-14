#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include <sstream>
#include "WriteExamResultToFiles.h"
#include "FinalResult.h"
#include "../entities/Exam.h"
#include "../entities/Applicant.h"
#include "../entities/Lecturer.h"
using namespace std;

bool showResultToClient(bool isPassed, Exam newExam, vector<Applicant> applicants, int userID,
    vector<Lecturer> lecturers, int chosenLecturerId) {

    if (isPassed) {
        string filePath = "database/approved_applicants.txt";
        vector<FinalResult> approvedExams;
        int maxID = 0;

        try {
            ifstream file(filePath);
            if (!file.is_open()) {
                throw runtime_error("File not found");
            }

            string line;
            int applicantID = 0, examID, lecturerID, facultyID;
            string applicantFirstName, applicantLastName, applicantMiddleName;
            string lecturerFirstName, lecturerLastName, lecturerMiddleName;
            int applicantAge, lecturerAge;
            double mathMark, ukrMark, histMark, exam_grade;
            while (getline(file, line)) {
                if (line.empty()) {
                    continue;
                }

                stringstream ss(line);

                // No data in file
                ss >> applicantID;
                ss >> applicantFirstName >> applicantLastName >> applicantMiddleName >> applicantAge;

                getline(file, line);
                stringstream ss2(line);
                ss2 >> examID >> mathMark >> ukrMark >> histMark >> exam_grade;

                getline(file, line);
                stringstream ss3(line);
                ss3 >> lecturerID >> lecturerFirstName >> lecturerLastName >> lecturerMiddleName >> lecturerAge >> facultyID;

                // Create new obj
                FinalResult obj
                (
                    applicantID, applicantFirstName, applicantLastName, applicantMiddleName, applicantAge,
                    examID, mathMark, ukrMark, histMark, exam_grade,
                    lecturerID, lecturerFirstName, lecturerLastName, lecturerMiddleName, lecturerAge, facultyID
                );

                approvedExams.push_back(obj);
                // Close file for reading
                file.close();
            }

            // Find maxID value
            if (applicantID == 0) {
                newExam.setExamId(1);
                cout << "\n-------------------------------------------" << endl;
                cout << newExam.toString() << endl;
                cout << "\n-------------------------------------------" << endl;
            }
            else {
                for (auto& exam : approvedExams) {
                    if (exam.getExamId() > maxID) {
                        maxID = exam.getExamId();
                    }
                }
                cout << "\n\n MAX ID: " << maxID << endl;
                // Now we can save our approved_exam, previously added 1 to maxID value
                newExam.setExamId(maxID + 1);
                cout << "\n-------------------------------------------" << endl;
                cout << newExam.toString() << endl;
                cout << "\n-------------------------------------------" << endl;
            }

            // Open the same file but for writing option
            ofstream fileExam(filePath, std::ios::app);

            // Write empty line before adding new approved exam
            fileExam << "\n\n";

            // Write approved exam data to file
            for (auto& applicant : applicants) {
                if (applicant.getId() == userID) {
                    fileExam << applicant.getId() << " " << applicant.getFirstName() << " " << applicant.getLastName()
                        << " " << applicant.getMiddleName() << " " << applicant.getAge() << "\n";
                }
            }

            fileExam << newExam.getExamId() << " " << newExam.getMathMark() << " " << newExam.getUkrMark()
                << " " << newExam.getHistorymark() << " " << newExam.getExamGrade() << "\n";

            for (auto& lecturer : lecturers) {
                if (lecturer.getId() == chosenLecturerId) {
                    fileExam << lecturer.getId() << " " << lecturer.getFirstName() << " " << lecturer.getLastName()
                        << " " << lecturer.getMiddleName() << " " << lecturer.getAge() << " " << lecturer.getFacultyId();
                }
            }

            cout << "\n----------- Result -----------\n";
            cout << "New exam successfully has been saved into " + filePath + "\n";
            cout << "------------------------------\n";

            // Close file for writing
            file.close();
        }
        catch (exception& err) {
            cerr << "Error opening file: " << err.what() << std::endl;
            throw err;
        }

        return true;
    }

    else {
    string filePath = "database/rejected_applicants.txt";
    vector<FinalResult> approvedExams;
    int maxID = 0;

    try {
        ifstream file(filePath);
        if (!file.is_open()) {
            throw runtime_error("File not found");
        }

        string line;
        int applicantID = 0, examID, lecturerID, facultyID;
        string applicantFirstName, applicantLastName, applicantMiddleName;
        string lecturerFirstName, lecturerLastName, lecturerMiddleName;
        int applicantAge, lecturerAge;
        double mathMark, ukrMark, histMark, exam_grade;
        while (getline(file, line)) {
            if (line.empty()) {
                continue;
            }

            stringstream ss(line);

            // No data in file
            ss >> applicantID;
            ss >> applicantFirstName >> applicantLastName >> applicantMiddleName >> applicantAge;

            getline(file, line);
            stringstream ss2(line);
            ss2 >> examID >> mathMark >> ukrMark >> histMark >> exam_grade;

            getline(file, line);
            stringstream ss3(line);
            ss3 >> lecturerID >> lecturerFirstName >> lecturerLastName >> lecturerMiddleName >> lecturerAge >> facultyID;

            // Create new obj
            FinalResult obj
            (
                applicantID, applicantFirstName, applicantLastName, applicantMiddleName, applicantAge,
                examID, mathMark, ukrMark, histMark, exam_grade,
                lecturerID, lecturerFirstName, lecturerLastName, lecturerMiddleName, lecturerAge, facultyID
            );

            approvedExams.push_back(obj);
            // Close file for reading
            file.close();
        }

        // Find maxID value
        if (applicantID == 0) {
            newExam.setExamId(1);
            cout << "\n-------------------------------------------" << endl;
            cout << newExam.toString() << endl;
            cout << "\n-------------------------------------------" << endl;
        }
        else {
            for (auto& exam : approvedExams) {
                if (exam.getExamId() > maxID) {
                    maxID = exam.getExamId();
                }
            }
            cout << "\n\n MAX ID: " << maxID << endl;
            // Now we can save our approved_exam, previously added 1 to maxID value
            newExam.setExamId(maxID + 1);
            cout << "\n-------------------------------------------" << endl;
            cout << newExam.toString() << endl;
            cout << "\n-------------------------------------------" << endl;
        }

        // Open the same file but for writing option
        ofstream fileExam(filePath, std::ios::app);

        // Write empty line before adding new approved exam
        fileExam << "\n\n";

        // Write approved exam data to file
        for (auto& applicant : applicants) {
            if (applicant.getId() == userID) {
                fileExam << applicant.getId() << " " << applicant.getFirstName() << " " << applicant.getLastName()
                    << " " << applicant.getMiddleName() << " " << applicant.getAge() << "\n";
            }
        }

        fileExam << newExam.getExamId() << " " << newExam.getMathMark() << " " << newExam.getUkrMark()
            << " " << newExam.getHistorymark() << " " << newExam.getExamGrade() << "\n";

        for (auto& lecturer : lecturers) {
            if (lecturer.getId() == chosenLecturerId) {
                fileExam << lecturer.getId() << " " << lecturer.getFirstName() << " " << lecturer.getLastName()
                    << " " << lecturer.getMiddleName() << " " << lecturer.getAge() << " " << lecturer.getFacultyId();
            }
        }

        cout << "\n----------- Result -----------\n";
        cout << "New exam successfully has been saved into " + filePath + "\n";
        cout << "------------------------------\n";

        // Close file for writing
        file.close();
    }
    catch (exception& err) {
        cerr << "Error opening file: " << err.what() << std::endl;
        throw err;
    }

        return false;
    }
}