#include "Person.h"

#include "Person.h"
#include <iostream>

// Constructor
Person::Person(const std::string& name, const std::string& email)
        : name(name), email(email) {}

// Copy constructor
Person::Person(const Person& other)
        : name(other.name), email(other.email) {}

// Copy assignment operator
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        email = other.email;
    }
    return *this;
}
void Person::sendEmail(const std::string& message) const {
    std::cout << "Email to " << email << ": " << message << std::endl;
}

 void Person::suntBolnav() const {}
// Destructor
Person::~Person() {
    // Handle any dynamic resource management if necessary
}
