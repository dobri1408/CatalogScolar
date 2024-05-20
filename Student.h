//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H
#pragma once
#include <string>
#include <vector>
#include "Nota.h"
#include "Person.h"  // Include the Nota header to use the Nota class
#include "Parinte.h" // Include the Parinte header to use the Parinte class
#include <chrono>

class Student : public Person  {
private:
    int id;
    std::vector<Nota> note;  // Dynamic array of grades
    Parinte parinte;

    std::vector<std::pair<std::string, std::string>> scutiri;
public:
    Student(const std::string &nume, const std::string &email, const Parinte &p, const int &id);
    Student(const std::string &nume, const std::string &email, const int &id, const std::vector<Nota> &noteArray);
    Student(const Student& other);
    Student& operator=(const Student& other);


    void adaugaNota(const Nota& nota);
    double calculeazaMedia() const;
    bool esteCorigent() const;
    int notaMaxima() const;
    std::string getDescription() const override;  // Ensure this is declared to override
    void suntBolnav()   override;
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

#endif //OOP_STUDENT_H
