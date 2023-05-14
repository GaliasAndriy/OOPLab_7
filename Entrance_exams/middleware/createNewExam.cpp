#include <iostream>
#include <vector>
#include "../entities/Exam.h"
#include "../faculties/Faculty.h"
using namespace std;

Exam generateExam() {
    Exam newExam;
    int exam_id;
    double mathMark, ukrMark, histMark;
    bool validInput1 = false, validInput2 = false, validInput3 = false;
    bool validMathMark = false, validUkrMark = false, validHistMark = false;
    do {
        cout << "\n Enter next marks for the exam:" << endl;
        try {
            cout << " Enter math points: ";
            cin >> mathMark;
            if (cin.fail()) {
                throw runtime_error("Invalid input: not an double or int value");
            }
            if (mathMark < 100 || mathMark > 200) {
                throw runtime_error("Wrong entered mark! Mark for subject should be from 100 to 200.");
            }
            validInput1 = true;
            validMathMark = true;

            cout << " Enter ukrainian languge points: ";
            cin >> ukrMark;
            if (cin.fail()) {
                throw runtime_error("Invalid input: not an double or int value");
            }
            if (ukrMark < 100 || ukrMark > 200) {
                throw runtime_error("Wrong entered mark! Mark for subject should be from 100 to 200.");
            }
            validInput2 = true;
            validUkrMark = true;

            cout << " Enter history of Ukraine points: ";
            cin >> histMark;
            if (cin.fail()) {
                throw runtime_error("Invalid input: not an double or int value");
            }
            if (histMark < 100 || histMark > 200) {
                throw runtime_error("Wrong entered mark! Mark for subject should be from 100 to 200.");
            }
            validInput3 = true;
            validHistMark = true;
        }
        catch (const runtime_error& e) {
            cerr << e.what() << endl;
            cin.clear();  // Clear the error flag on the input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput1 || !validInput2 || !validInput3 || !validMathMark || !validUkrMark || !validHistMark);
    
    newExam.setMathMark(mathMark);
    newExam.setUkrMark(ukrMark);
    newExam.setHistoryMark(histMark);

    return newExam;
}