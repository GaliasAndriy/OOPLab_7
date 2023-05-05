#include <fstream>
#include <sstream>
#include "ReadApplicantsFile.h"
using namespace std;

vector<Applicant> readFile(const string& fileName) {
    vector<Applicant> applicants;

    try {
        ifstream file(fileName);
        if (!file.is_open()) {
            throw runtime_error("File not found");
        }

        string line;
        while (getline(file, line)) {
            try {
                if (line.empty()) {
                    continue;
                }
                int id, age;
                string firstName, lastName, middleName, phone_number, email, passport;

                stringstream ss(line);
                ss >> id;
                if (ss.fail()) {
                    throw runtime_error("Invalid ID on line! " + line);
                }
                else {
                    // Check whether the id already exists
                    bool idExists = false;
                    for (auto& person : applicants) {
                        if (person.getId() == id) {
                            idExists = true;
                            break;
                        }
                    }
                    if (!idExists) {
                        ss >> firstName >> lastName >> middleName >> age;
                        getline(file, phone_number);
                        getline(file, email);
                        getline(file, passport);

                        Applicant person(id, firstName, lastName, middleName, age, phone_number, email, passport);
                        applicants.push_back(person);
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

    return applicants;
}