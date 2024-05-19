//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_PERSON_H
#define OOP_PERSON_H
#pragma once
#include <string>

class Person {
protected:
    std::string name;
    std::string email;

public:
    Person(const std::string& name, const std::string& email);  // Constructor
    Person(const Person& other);  // Copy constructor
    Person& operator=(const Person& other);  // Copy assignment operator
    virtual ~Person();  // Virtual destructor

    virtual std::string getDescription() const = 0;  // Pure virtual function
    virtual void sendEmail(const std::string& message) const; // Virtual function for sending email
    virtual void suntBolnav() const ;
};

#endif //OOP_PERSON_H
