#include "Scoala.h"
#include <iostream>
#include <algorithm>
#include "Exceptions.h"

std::string Scoala::currentAcademicYear = "2024-2025";

Scoala::Scoala(const std::string &numeScoala) : numeScoala(numeScoala),maximumClassesCapacity(2) {

}

void Scoala::adaugaClasa(const Clasa& clasa) {

        if ((int)clase.size() == maximumClassesCapacity) {
            throw SchoolAdminException("Nu mai sunt sali pentru inca o clasa");
        }
        clase.push_back(clasa);

    std::cout << "Clasa " << clasa.getNumeClasa() << " a fost adaugata la scoala " << numeScoala << "." << std::endl;
}

std::vector<BarChartStruct> Scoala::sorteazaClaseDupaMedie() {
    std::sort(clase.begin(), clase.end(), [](const Clasa &a, const Clasa &b) {
        return a.calculeazaMediaGenerala() > b.calculeazaMediaGenerala();
    });

    std::vector<BarChartStruct> claseSortate;
    for (const auto& c : clase) {
        claseSortate.push_back({c.getNumeClasa(), c.calculeazaMediaGenerala()});
    }
    return claseSortate;
}


void Scoala::simuleazaZiDeScoala() {
    for (auto clasa:clase){
        clasa.simuleazaZiDeScoala();
    }
}