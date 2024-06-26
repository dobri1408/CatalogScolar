//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_ElevPrimar_H
#define OOP_ElevPrimar_H
#pragma once
#include <vector>
#include "Nota.h"
#include "Person.h"  // Include the Nota header to use the Nota class
#include "Parinte.h" // Include the Parinte header to use the Parinte class
#include <chrono>

class ElevPrimar: public Person  {
private:
    int id;
    std::vector<Nota<std::string>> note;  // Dynamic array of grades
    Parinte parinte;

    std::vector<std::pair<std::string, std::string>> scutiri;
public:
    ElevPrimar(const std::string &nume, const std::string &email, const Parinte &p, const int &id);
    ElevPrimar(const std::string &nume, const std::string &email, const int &id, const std::vector<Nota<std::string>> &noteArray);
    ElevPrimar(const ElevPrimar& other);
    ElevPrimar& operator=(const ElevPrimar& other);


    void adaugaNota(const Nota<std::string>& nota);
    double calculeazaMedia() const;
    bool esteCorigent() const;
    int notaMaxima() const;
    std::string getDescription() const override;  // Ensure this is declared to override
    void suntBolnav()   override;
    friend std::ostream& operator<<(std::ostream& os, const ElevPrimar& s);
};

#endif //OOP_ElevPrimar_H
