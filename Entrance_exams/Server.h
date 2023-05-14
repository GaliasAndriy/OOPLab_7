#pragma once
#include "entities/Applicant.h"
#include "entities/Lecturer.h"
#include "faculties/Faculty.h"

class Server {
public:
	vector<Applicant> showApplicantList();
	void showLecturerList();
	vector<Faculty> showFacultyList();
	void showApprovedExamsList();
	void showRejectedExamList();
	void creatNewExam();
	void findApplicantByName();
	void findFacultyById();
	void showApplicantExams();

	static std::string trim(const std::string& str);
};