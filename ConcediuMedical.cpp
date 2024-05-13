#include "ConcediuMedical.h"
#include <iostream>

ConcediuMedical::ConcediuMedical( std::string& start,  std::string& end)
        : dataInceput(start), dataSfarsit(end) {}
ConcediuMedical::ConcediuMedical(){}


void ConcediuMedical::afiseazaDetalii() const {
    std::cout << "Concediu medical de la " << dataInceput << " pana la " << dataSfarsit << std::endl;
}
