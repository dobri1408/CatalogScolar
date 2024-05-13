#include "Profesor.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

// Constructor


Profesor::Profesor(const std::string &name, const std::string &email)
        : Person(name, email) {}

// Copy constructor
Profesor::Profesor(const Profesor &other)
        : Person(other), subjects(other.subjects) {}

// Copy assignment operator
Profesor& Profesor::operator=(const Profesor &other) {
    if (this != &other) {
        Person::operator=(other);  // Call the base class assignment operator
        subjects = other.subjects;
    }
    return *this;
}

// Destructor
Profesor::~Profesor() {}

void Profesor::addSubject(const std::string &subject) {
    subjects.push_back(subject);
}

std::vector<std::string> Profesor::getSubjects() const {
    return subjects;
}


std::string Profesor::getDescription() const {
    return name+ " " + email;
}
 void Profesor::suntBolnav()  {
     auto now = std::chrono::system_clock::now();
     auto now2 = std::chrono::system_clock::now();

     std::time_t current_time = std::chrono::system_clock::to_time_t(now);

     std::tm* current_tm = std::localtime(&current_time);

     std::ostringstream current_date_stream;
     current_date_stream << std::put_time(current_tm, "%Y-%m-%d");


     std::vector<std::pair<std::string, std::string>> dates;

     concedii_medicale.push_back(std::make_pair(current_date_stream.str(), current_date_stream.str()));
     for(auto concediu:concedii_medicale) {
         std::cout<<concediu.first<< " " << concediu.second<<"\n";}
     //medicale.push()
}

static std::tm parseDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    tm.tm_isdst = -1;  // Not considering daylight saving time
    return tm;
}

static bool isDateInRange(const std::string& currentDateStr, const std::string& startDateStr, const std::string& endDateStr) {
    std::tm currentDate = parseDate(currentDateStr);
    std::tm startDate = parseDate(startDateStr);
    std::tm endDate = parseDate(endDateStr);

    time_t currentEpoch = std::mktime(&currentDate);
    time_t startEpoch = std::mktime(&startDate);
    time_t endEpoch = std::mktime(&endDate);

    return (currentEpoch >= startEpoch && currentEpoch <= endEpoch);
}


bool Profesor::esteProfesorulInConcediu() const{

    auto now = std::chrono::system_clock::now();
    // Convert it to a time_t object
    std::time_t now_t = std::chrono::system_clock::to_time_t(now);
    // Convert time_t to tm as local time
    std::tm* now_tm = std::localtime(&now_t);

    // Use stringstream to format the date
    std::stringstream ss;
    ss << std::put_time(now_tm, "%Y-%m-%d");  // Format the date as "Year-Month-Day"
    std::string today = ss.str();

    for(auto concediu:concedii_medicale) {
        std::cout<<concediu.first<< " " << concediu.second<<"\n";
        if (isDateInRange(today, concediu.first, concediu.second)) {
            return true;
        }
    }
    return false;
}
