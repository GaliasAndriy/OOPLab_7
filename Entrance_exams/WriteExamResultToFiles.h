#include <iostream>
#include "entities/Exam.h"
#include "entities/Applicant.h"
#include "entities/Lecturer.h"
using namespace std;

bool showResultToClient(bool isPassed, Exam newExam, vector<Applicant> applicants, int userID,
	vector<Lecturer> lecturers, int chosenLecturerId);