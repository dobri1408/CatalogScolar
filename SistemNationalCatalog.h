//
// Created by Dobricean Ioan Dorian on 27.05.2024.
//

#ifndef OOP_SISTEMNATIONALCATALOG_H
#define OOP_SISTEMNATIONALCATALOG_H
#include "Scoala.h"

class SistemNationalCatalog {

private:
    std::vector<Scoala>scoli;
public:
    explicit SistemNationalCatalog(const std::vector<Scoala> &scoli);

    SistemNationalCatalog();

    void CreeeazaUnScenariuInitial();

};


#endif //OOP_SISTEMNATIONALCATALOG_H
