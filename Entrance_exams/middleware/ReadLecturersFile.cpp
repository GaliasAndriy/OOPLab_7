#include <fstream>
#include <sstream>
#include "ReadLecturersFile.h"
using namespace std;

vector<Lecturer> readLecturerFile(const string& fileName) {
    vector<Lecturer> lecturers;

    try {
        ifstream file(fileName);
        if (!file.is_open()) {
            throw runtime_error("File not found");
        }

        string line;
        while (getline(file, line)) {
            try {
                int id, age;
                string firstName, lastName, middleName, title;

                stringstream ss(line);
                ss >> id;
                if (ss.fail()) {
                    throw runtime_error("Invalid ID on line! " + line);
                }
                else {
                    // Check whether the id already exists
                    bool idExists = false;
                    for (auto& person : lecturers) {
                        if (person.getId() == id) {
                            idExists = true;
                            break;
                        }
                    }
                    if (!idExists) {
                        ss >> firstName >> lastName >> middleName >> age >> title;

                        Lecturer person(id, firstName, lastName, middleName, age, title);
                        lecturers.push_back(person);
                    }
                    else {
                        cout << "Error: ID " << id << " already exists." << std::endl;
                    }
                }
            }
            catch (exception& e) {
                cerr << "Error processing line: " << e.what() << std::endl;
            }
        }

    }
    catch (exception& err) {
        cerr << "Error opening file: " << err.what() << std::endl;
        throw err;
    }

    return lecturers;
}