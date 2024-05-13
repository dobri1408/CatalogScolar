//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_CONCEDIUMEDICAL_H
#define OOP_CONCEDIUMEDICAL_H

#include <string>

class ConcediuMedical {



    std::string dataInceput;
    std::string dataSfarsit;

public:
    ConcediuMedical(std::string& start, std::string& end);
    ConcediuMedical();
    void afiseazaDetalii() const;
};
#endif //OOP_CONCEDIUMEDICAL_H
