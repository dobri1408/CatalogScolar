#include "CatalogFactory.h"
#include <cctype>  // For std::isdigit
#include <stdexcept>  // For std::invalid_argument
#include "Catalog.h"
#include "ElevPrimar.h"
#include "ElevGimnaziu.h"
CatalogVariant CatalogFactory::createCatalog(const std::string& className) {
    if (className.empty() || !std::isdigit(className[0])) {
        throw std::invalid_argument("Class name must start with a digit.");
    }

    // Extract the numeric part for the grade from the class name
    size_t idx = 0;
    while (idx < className.size() && std::isdigit(className[idx])) {
        idx++;
    }

    // Convert the extracted number to an integer
    int grade = std::stoi(className.substr(0, idx));

    if (grade >= 1 && grade <= 4) {
        // Grades 1-4 are primary students
        return Catalog<ElevPrimar>();
    } else if (grade >= 5 && grade <= 12) {
        // Grades 5-12 are gymnasium students
        return Catalog<ElevGimnaziu>();
    } else {
        throw std::invalid_argument("Invalid grade level.");
    }
}