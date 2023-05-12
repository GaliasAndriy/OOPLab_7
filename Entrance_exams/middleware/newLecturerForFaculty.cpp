#include <fstream>
#include <sstream>
#include "newLecturerForFaculty.h"
#include "ReadLecturersFile.h"
#include "WriteNewLecturerToFile.h"
using namespace std;

int createNewLecturer(int facultyID) {
    int validID = false;
    string lecturerFile = "database/lecturers.txt";
    vector<Lecturer> lecturers = readLecturerFile(lecturerFile);

    bool idExists = true;
    int newLecturerId, newAge;
    string newFirstName, newLastName, newMiddleName, newTitle;
    cout << "\nNo lecturers found for this faculty." << endl;
    cout << "\nFill the data about a lecturer: " << endl;
    do {
        try {
            cout << "Enter lecturer ID: ";
            cin >> newLecturerId;
            if (cin.fail()) {
                throw runtime_error("Invalid ID! - " + newLecturerId);
            }
            validID = true;

            for (auto& lecturer : lecturers) {
                if (lecturer.getId() == newLecturerId) {
                    throw runtime_error("ID already exists! Enter unique ID.");
                }
            }
            idExists = false;

            cout << "\n Enter first name: "; cin >> newFirstName;
            cout << " Enter last name: "; cin >> newLastName;
            cout << " Enter middle name: "; cin >> newMiddleName;
            do {
                cout << " Enter age: ";
                cin >> newAge;
                if (newAge < 21 || newAge > 90) {
                    cout << "Entered age is not between 21 and 90. Try again." << endl;
                }
            } while (newAge < 21 || newAge > 90);
            cout << " Enter lecturer title: "; cin >> newTitle;

            // Create a new lecturer object and push it into lecturers.txt
            Lecturer lecturer;
            lecturer.setId(newLecturerId);
            lecturer.setFirstName(newFirstName);
            lecturer.setLastName(newLastName);
            lecturer.setMiddleName(newMiddleName);
            lecturer.setAge(newAge);
            lecturer.setFacultyId(facultyID);
            lecturer.setTitle(newTitle);

            // Write the lecturer to the file
            writeLecturerToFile(lecturer);
            cout << "\n New lecturer has been written successfully to the lecturers.txt file" << endl;
        }
        catch (runtime_error& e) {
            cerr << e.what() << endl;
            cin.clear();  // Clear the error flag on the input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!validID || idExists);

    return newLecturerId;
}

