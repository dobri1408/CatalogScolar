// SchoolAPI.cpp

#include "SchoolAPI.h"

SchoolAPI::SchoolAPI() {
    // Constructor implementation
    // Here you might initialize data or load it from a database or file
}

SchoolAPI::~SchoolAPI() {
    // Destructor implementation
    // Cleanup, saving data, etc.
}

double SchoolAPI::calculateClassAverage(const std::string& classId) {
    // This would compute and return the average grade for a specified class
    const auto& grades = classGrades[classId];
    if (grades.empty())
        return 0.0;

    double sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

std::vector<int> SchoolAPI::getStudentGrades(const std::string& studentId) {
    // This would return a list of grades for the specified student
    return studentGrades[studentId];
}
