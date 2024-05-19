#include "Student.h"
#include <iostream> // For std::cout and std::endl
#include "Exceptions.h"
#include <iomanip>
#include <ctime>
#include <sstream>


Student::Student(const std::string &nume,const std::string &email, const Parinte &p, const int &id)
        : Person(nume,email), id(id),parinte(p) {}

Student::Student(const std::string &nume,const std::string &email, const int &id, const std::vector<Nota> &noteArray)
        :Person(nume,email), id(id), note(noteArray) {}

Student::Student(const Student& other)
        : Person(other), id(other.id), note(other.note), parinte(other.parinte),  scutiri(other.scutiri) {}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Person::operator=(other);
        id = other.id;
        note = other.note;
        parinte = other.parinte;
        scutiri = other.scutiri;

    }
    return *this;
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
    std::tm startDate =parseDate(startDateStr);
    std::tm endDate =parseDate(endDateStr);

    time_t currentEpoch = std::mktime(&currentDate);
    time_t startEpoch = std::mktime(&startDate);
    time_t endEpoch = std::mktime(&endDate);

    return (currentEpoch >= startEpoch && currentEpoch <= endEpoch);
}


void Student::adaugaNota(const Nota& nota) {
    auto now = std::chrono::system_clock::now();
    // Convert it to a time_t object
    std::time_t now_t = std::chrono::system_clock::to_time_t(now);
    // Convert time_t to tm as local time
    std::tm* now_tm = std::localtime(&now_t);

    // Use stringstream to format the date
    std::stringstream ss;
    ss << std::put_time(now_tm, "%Y-%m-%d");  // Format the date as "Year-Month-Day"
    std::string today = ss.str();
    try {

        if (nota.getMaterie()->getProfesor()->esteProfesorulInConcediu()) {
            throw TeachingException("Profesorul este in concediu medical, nu este posibila nota");
        }

        for (auto concediu: scutiri) {
            if (isDateInRange(today, concediu.first, concediu.second))
                throw TeachingException("Elevul are scutire, nu este posibila nota");
        }
        if (parinte.isDataSet()) {
            parinte.sendEmail(getDescription() + " a primit o nota: " + std::to_string(nota.getValoare()) + " la " +
                              nota.getMaterie()->getMaterie());
        }
        else   throw TeachingException("Elevul are parinte setat, nu este posibila nota");
        note.push_back(nota);
    }catch (const std::exception& e)
    {
        std::cerr << "A aparut o eroare: " << e.what() << std::endl;
    }
}

std::string Student::getDescription() const {
    return name + ", " + std::to_string(id)+","; // Properly implemented as required by the abstract method in Person
}

double Student::calculeazaMedia() const {
    if (note.empty()) return 0.0;
    double suma = 0.0;
    for (const auto& n : note) {
        suma += n.getValoare();
    }
    return suma / note.size();
}

bool Student::esteCorigent() const {
    return calculeazaMedia() < 5.0;
}

int Student::notaMaxima() const {
    int max = 0;
    for (const auto& n : note) {
        if (n.getValoare() > max) {
            max = n.getValoare();
        }
    }
    return max;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.getDescription();
    if (!s.note.empty()) {
        for (const auto& n : s.note) {
            os << n << " ";
        }
    }
    os<<"\n";
    return os;
}

void Student::suntBolnav()const   {
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    std::tm* current_tm = std::localtime(&current_time);

    if (current_tm == nullptr) {
        std::cerr << "Failed to convert current time to local time." << std::endl;

    }

    std::ostringstream current_date_stream;
    current_date_stream << std::put_time(current_tm, "%Y-%m-%d");

    std::vector<std::pair<std::string, std::string>> scutiri;
    scutiri.push_back(std::make_pair(current_date_stream.str(), current_date_stream.str()));

}