//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_SCOALA_H
#define OOP_SCOALA_H
#pragma once
#include <vector>
#include <string>
#include "Clasa.h"
#include "Barchart.h"

class Scoala {
private:
    std::string numeScoala;
    std::vector<Clasa> clase;

    int maximumClassesCapacity;
    static std::string currentAcademicYear;
public:
    explicit Scoala(const std::string &numeScoala);

    void adaugaClasa(const Clasa& clasa);
    void simuleazaZiDeScoala();
    static void setAcademicYear(const std::string& year) {
        currentAcademicYear = year;  // Set the academic year for all schools
    }
    void exportCSV() const;



    static std::string getAcademicYear() {
        return currentAcademicYear;
    }

    std::vector<BarChartStruct> sorteazaClaseDupaMedie();
};

#endif //OOP_SCOALA_H
