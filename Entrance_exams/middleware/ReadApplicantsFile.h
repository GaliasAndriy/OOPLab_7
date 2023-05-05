#pragma once
#include <vector>
#include <string>
#include "../entities/Applicant.h"

std::vector<Applicant> readFile(const std::string& fileName);