#pragma once
#include <vector>
#include <string>
#include "../entities/Lecturer.h"

std::vector<Lecturer> readLecturerFile(const std::string& fileName);