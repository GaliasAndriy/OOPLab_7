#include <iostream>
#include "ChooseObject.h"
using namespace std;

int chooseApplicant(vector<Applicant> applicants) {
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

	return userID;
}

int chooseFaculty(vector<Faculty> faculties) {
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

    return facultyID;
}