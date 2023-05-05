#include "Faculty.h"
#include "BaseFaculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty() {
	specialty = "no data";
}

Faculty& Faculty::operator=(const Faculty& s) {
    this->BaseFaculty::operator=(s);
    specialty = s.specialty;
    return *this;
}

string Faculty::getSpecialty () {
    return specialty;
}
void Faculty::setSpecialty(string spec) {
    specialty = spec;
}

string Faculty::toString() {
    string ID = to_string(BaseFaculty::getId());
    cout << "\n ID: ";
    string result = "\033[32m" + ID + "\033[0m" 
        + BaseFaculty::toString() + "\n Specialty: " + specialty + "\n";  
    return result;
}