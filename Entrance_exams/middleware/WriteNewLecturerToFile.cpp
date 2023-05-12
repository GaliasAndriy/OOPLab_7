#include <fstream>
#include <sstream>
#include "ReadLecturersFile.h"
using namespace std;

void writeLecturerToFile(Lecturer& lecturer) {
    ofstream lecturersFile("database/lecturers.txt", ios::app);
    if (!lecturersFile) {
        cerr << "Error: could not open file" << endl;
        return;
    }

    // Write empty line before adding new lecturer
    lecturersFile << "\n";

    // Write lecturer data to file
    lecturersFile << lecturer.getId() << " " << lecturer.getFirstName() << " " 
        << lecturer.getLastName() << " " << lecturer.getMiddleName() << " " << lecturer.getAge() 
        << " " << lecturer.getFacultyId() << endl;

    // Write lecturer title on separate line
    lecturersFile << lecturer.getTitle() << endl;

    // Close the file
    lecturersFile.close();
}