// SchoolAPI.h

#ifndef SCHOOL_API_H
#define SCHOOL_API_H

#include <vector>
#include <string>
#include <unordered_map>

class SchoolAPI {
public:
    SchoolAPI();  // Constructor
    ~SchoolAPI(); // Destructor

    // Function to calculate the average grade of a class
    double calculateClassAverage(const std::string& classId);

    // Function to get grades for a specific student
    std::vector<int> getStudentGrades(const std::string& studentId);

private:
    // Example of potential private data members
    std::unordered_map<std::string, std::vector<int>> classGrades;
    std::unordered_map<std::string, std::vector<int>> studentGrades;
};

#endif // SCHOOL_API_H
