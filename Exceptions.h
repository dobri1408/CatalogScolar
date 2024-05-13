//
// Created by Dobricean Ioan Dorian on 11.05.2024.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H


#include <stdexcept>
#include <string>

class InvalidMaterieException : public std::runtime_error {
public:
    explicit InvalidMaterieException(const std::string& msg)
            : std::runtime_error("Invalid Materie: " + msg) {}
};

class TeachingException : public std::runtime_error {
public:
    explicit TeachingException(const std::string& msg)
            : std::runtime_error("Teaching Error: " + msg) {}
};

class SchoolAdminException : public std::runtime_error {
public:
    explicit SchoolAdminException(const std::string& msg)
            : std::runtime_error("School Administration Error: " + msg) {}
};



#endif //OOP_EXCEPTIONS_H
