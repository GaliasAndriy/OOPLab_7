// libraries
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

// Header files
#include "entities/Applicant.h"
#include "entities/Lecturer.h"
#include "faculties/Faculty.h"
#include "entities/Exam.h"
#include "middleware/ReadApplicantsFile.h"
#include "middleware/ReadLecturersFile.h"
#include "middleware/ReadFacultyFile.h"
#include "middleware/WriteNewLecturerToFile.h"
#include "middleware/newLecturerForFaculty.h"
#include "middleware/ChooseObject.h"
#include "middleware/CreateNewExam.h"
#include "middleware/FinalResult.h"
#include "middleware/WriteExamResultToFiles.h"

#include "Server.h"

int main() {
    srand(time(nullptr));
    Server server;

   char choice;
   do {
       cout << "---------------------------------" << endl;
       cout << "|" << "\033[33m" << "        Entrance Exams" << "\033[0m" << "         |" << endl;
       cout << "---------------------------------" << endl;
       cout << "|" << "\033[32m" << "  Main Menu:" << "\033[0m" << "                   |" << endl;
       cout << "|  1. Show list of applicants   |" << endl;
       cout << "|  2. Show list of faculties    |" << endl;
       cout << "|  3. Show list of lecturers    |" << endl;
       cout << "|  4. Show list of passed exams |" << endl;
       cout << "|  5. Show list of failed exams |" << endl;
       cout << "|  6. New exam                  |" << endl;
       cout << "|  7. Find applicant by name    |" << endl;
       cout << "|  8. Find faculty by ID        |" << endl;
       //cout << "|  9. Show applicant exams      |" << endl;
       cout << "|  9. Clear console             |" << endl;
       cout << "|  10. Enter 'e' to exit        |" << endl;
       cout << "---------------------------------" << endl;

       cout << " Your choice: ";
       cin >> choice;

       switch (choice) {
       case '1':
           server.showApplicantList();
           break;
       case '2':
           server.showFacultyList();
           break;
       case '3':
           server.showLecturersList();
           break;
       case '4':
           server.showApprovedExamsList();
           break;
       case '5':
           //server.showRejectedExamList();
           break;
       case '6':
           server.createNewExam();
           break;
       case '7':
           cout << "\n Find applicant by their first and last name" << endl;
           server.findApplicantByName();
           break;
       case '8':
           cout << "\n Find faculty by ID" << endl;
           server.findFacultyById();
           break;
       case '9':
           system("cls");
           break;
       case 'e':
           break;
       default:
           cout << "Invalid choice. Please enter a valid option or 'e' to exit." << endl;
       }

   } while (choice != 'e');

    return 0;
}