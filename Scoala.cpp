#include "Scoala.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Exceptions.h"

std::string Scoala::currentAcademicYear = "2024-2025";

Scoala::Scoala(const std::string &numeScoala) : numeScoala(numeScoala),maximumClassesCapacity(2) {

}

void Scoala::adaugaClasa(const auto& clasa) {

        if ((int)clase.size() == maximumClassesCapacity) {
            throw SchoolAdminException("Nu mai sunt sali pentru inca o clasa");
        }
        clase.push_back(clasa);

        claseSortate.push_back({clasa.getNumeClasa(), clasa.calculeazaMediaGenerala()});



    std::cout << "Clasa " << clasa.getNumeClasa() << " a fost adaugata la scoala " << numeScoala << "." << std::endl;
}



void Scoala::simuleazaZiDeScoala() {
    for (auto& clasa:clase){
        std::visit([](auto&& arg) -> void {
            arg.simuleazaZiDeScoala();
        }, clasa);
    }
}


void Scoala::exportCSV() const {
    for (auto& clasa : clase){
        std::string fileName =std::visit([](auto&& arg) -> std::string {
            return arg.getNumeClasa() + ".csv";
        }, clasa);;
        std::ofstream fout(fileName);
        if (std::holds_alternative<Clasa<ElevGimnaziu>>(clasa)) {
            auto& catalog = std::get<Clasa<ElevGimnaziu>>(clasa).getCatalog();
            catalog.afiseazaCatalog(fout);
            // Do something with catalog
        } else if (std::holds_alternative<Clasa<ElevPrimar>>(clasa)) {
            auto& catalog = std::get<Clasa<ElevPrimar>>(clasa).getCatalog();
            catalog.afiseazaCatalog(fout);
            // Do something with catalog
        }
        fout<<"Nume, ID, Note\n";


    }
}

const std::vector<BarChartStruct> &Scoala::getRank() const {
    return claseSortate;
}

template class Clasa<ElevGimnaziu>;
template class Catalog<ElevGimnaziu>;
template class Clasa<ElevPrimar>;
template class Catalog<ElevPrimar>;
template void Scoala::adaugaClasa<Clasa<ElevGimnaziu>>(const Clasa<ElevGimnaziu>&);
template void Scoala::adaugaClasa<Clasa<ElevPrimar>>(const Clasa<ElevPrimar>&);
