#pragma once
#include "entities/Applicant.h"
#include "entities/Lecturer.h"
#include "faculties/Faculty.h"

class Server {
public:
	vector<Applicant> showApplicantList();
	vector<Faculty> showFacultyList();
	void showApprovedExamsList();
	void showRejectedExamList();
	void createNewExam();
	void findApplicantByName();
	void findFacultyById();
	void showApplicantExams();
	vector<Lecturer> showLecturersRelatedToFaculty(int facultyID, string facultyName);
	vector<Lecturer> showLecturersList();
	int randomLecturer(vector<Lecturer> sortedLecturers, vector<Lecturer> lecturers, int facultyID);

	static std::string trim(const std::string& str);
};