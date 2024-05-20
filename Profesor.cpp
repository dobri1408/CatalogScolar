#include "Profesor.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <chrono>

// Constructor


Profesor::Profesor(const std::string &name, const std::string &email)
        : Person(name, email) {}

// Copy constructor
Profesor::Profesor(const Profesor &other)
        : Person(other), subjects(other.subjects),concedii_medicale(other.concedii_medicale) {}

// Copy assignment operator
Profesor& Profesor::operator=(const Profesor &other) {
    if (this != &other) {
        Person::operator=(other);  // Call the base class assignment operator
        subjects = other.subjects;

       concedii_medicale = other.concedii_medicale;


    }
    return *this;
}

// Destructor
Profesor::~Profesor() {}





std::string Profesor::getDescription() const {
    return name+ " " + email;
}
 void Profesor::suntBolnav()  {
     auto now = std::chrono::system_clock::now();
     // Convert the time to std::time_t
     std::time_t current_time = std::chrono::system_clock::to_time_t(now);
     // Convert std::time_t to std::tm for local time
     std::tm* current_tm = std::localtime(&current_time);
     // Check if current_tm is null, which would indicate an error
     if (!current_tm) {
         std::cerr << "Local time conversion failed." << std::endl;

     }

     // Use ostringstream to format the date
     std::ostringstream current_date_stream;
     current_date_stream << std::put_time(current_tm, "%Y-%m-%d");

     // Prepare a vector to store date pairs

     // Push formatted date as a pair to the vector
     concedii_medicale.push_back(std::make_pair(current_date_stream.str(), current_date_stream.str()));

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
