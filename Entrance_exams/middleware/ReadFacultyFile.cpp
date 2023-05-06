#include <fstream>
#include <sstream>
#include "ReadFacultyFile.h"
using namespace std;

vector<Faculty> readFacultyFile(const string& fileName) {
    vector<Faculty> faculties;

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
                int id;
                double math_coef, ukrainian_coef, history_coef, threshold_score;
                string specialty;

                stringstream ss(line);
                ss >> id;
                if (ss.fail()) {
                    throw runtime_error("Invalid ID on line! " + line);
                }
                else {
                    // Check whether the id already exists
                    bool idExists = false;
                    for (auto& faculty : faculties) {
                        if (faculty.getId() == id) {
                            idExists = true;
                            break;
                        }
                    }
                    if (!idExists) {
                        ss >> math_coef >> ukrainian_coef >> history_coef;
                        ss >> threshold_score;
                        if (threshold_score < 101 || threshold_score > 200) {
                            throw runtime_error("Invalid threshold_score on line! " + line);
                        } 
                        else {
                            getline(file, specialty);

                            Faculty faculty(id, math_coef, ukrainian_coef, history_coef, specialty, threshold_score);
                            faculties.push_back(faculty);
                        }
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

    return faculties;
}