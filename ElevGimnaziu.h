//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_ELEVGIMNAZIU_H
#define OOP_ELEVGIMNAZIU_H
#pragma once
#include <string>
#include <vector>
#include "Nota.h"
#include "Person.h"  // Include the Nota header to use the Nota class
#include "Parinte.h" // Include the Parinte header to use the Parinte class
#include <chrono>

class ElevGimnaziu: public Person  {
private:
    int id;
    std::vector<Nota<int>> note;  // Dynamic array of grades
    Parinte parinte;

    std::vector<std::pair<std::string, std::string>> scutiri;
public:
    ElevGimnaziu(const std::string &nume, const std::string &email, const Parinte &p, const int &id);
    ElevGimnaziu(const std::string &nume, const std::string &email, const int &id, const std::vector<Nota<int>> &noteArray);
    ElevGimnaziu(const ElevGimnaziu& other);
    ElevGimnaziu& operator=(const ElevGimnaziu& other);


    void adaugaNota(const Nota<int>& nota);
    double calculeazaMedia() const;
    bool esteCorigent() const;
    int notaMaxima() const;
    std::string getDescription() const override;  // Ensure this is declared to override
    void suntBolnav()   override;
    friend std::ostream& operator<<(std::ostream& os, const ElevGimnaziu& s);
};

#endif //OOP_ELEVGIMNAZIU_H
