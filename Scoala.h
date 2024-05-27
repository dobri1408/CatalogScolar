//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_SCOALA_H
#define OOP_SCOALA_H
#pragma once
#include <vector>
#include <string>
#include <variant>
#include "Clasa.h"
#include "Barchart.h"
#include "ElevPrimar.h"

class Scoala {
private:
    std::string numeScoala;
    std::vector<std::variant<Clasa<ElevGimnaziu>,Clasa<ElevPrimar>>> clase;
    std::vector<BarChartStruct> claseSortate;
    int maximumClassesCapacity;
    static std::string currentAcademicYear;
public:
    explicit Scoala(const std::string &numeScoala);

    void adaugaClasa(const auto& clasa);
    void simuleazaZiDeScoala();
    static void setAcademicYear(const std::string& year) {
        currentAcademicYear = year;  // Set the academic year for all schools
    }
    void exportCSV() const;

    const std::vector<BarChartStruct> &getRank() const;

    static std::string getAcademicYear() {
        return currentAcademicYear;
    }

};

#endif //OOP_SCOALA_H
