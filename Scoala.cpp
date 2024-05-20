#include "Scoala.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Exceptions.h"

std::string Scoala::currentAcademicYear = "2024-2025";

Scoala::Scoala(const std::string &numeScoala) : numeScoala(numeScoala),maximumClassesCapacity(2) {

}

void Scoala::adaugaClasa(const Clasa& clasa) {

        if ((int)clase.size() == maximumClassesCapacity) {
            throw SchoolAdminException("Nu mai sunt sali pentru inca o clasa");
        }
        clase.push_back(clasa);

        claseSortate.push_back({clasa.getNumeClasa(), clasa.calculeazaMediaGenerala()});



    std::cout << "Clasa " << clasa.getNumeClasa() << " a fost adaugata la scoala " << numeScoala << "." << std::endl;
}



void Scoala::simuleazaZiDeScoala() {
    for (auto& clasa:clase){
        clasa.simuleazaZiDeScoala();
    }
}


void Scoala::exportCSV() const {
    for (auto& clasa : clase){
        std::string fileName = clasa.getNumeClasa()+".csv";
        std::ofstream fout(fileName);
        auto catalog = clasa.getCatalog();
        fout<<"Nume, ID, Note\n";
        catalog.afiseazaCatalog(fout);

    }
}

const std::vector<BarChartStruct> &Scoala::getRank() const {
    return claseSortate;
}
