//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_CLASA_H
#define OOP_CLASA_H
#pragma once
#include <string>
#include "Catalog.h"  // Include the Catalog header because Clasa uses the Catalog class

class Clasa {
private:
    std::string numeClasa;
    Catalog catalog;
    std::vector<Materie*> materii;

    

public:
    Clasa(const std::string &numeClasa, const Catalog &catalog);
    double calculeazaMediaGenerala() const;
    std::string getNumeClasa() const;
    void simuleazaZiDeScoala();
    void checkAndPerformActivity(Person* person);

};


#endif //OOP_CLASA_H
