//
// Created by Dobricean Ioan Dorian on 10.05.2024.
#include "Parinte.h"

Parinte::Parinte(const std::string &name, const std::string &email)
        : Person(name, email) {}
Parinte::Parinte():Person("",""){}


// Copy constructor
Parinte::Parinte(const Parinte &other)
        : Person(other) {} // Invoke base class copy constructor

// Copy assignment operator
Parinte& Parinte::operator=(const Parinte &other) {
    if (this != &other) {
        Person::operator=(other); // Call base class assignment operator
    }
    return *this;
}


Parinte::~Parinte() {}

bool Parinte::isDataSet() {
    return !name.empty() && !email.empty();
}

std::string Parinte::getDescription() const {
    return "Parinte: " + name;  // Providing concrete implementation
}
 void Parinte::suntBolnav()  {
    std::cout<<"veriric daca copilul meu este blonav";
}

//
