//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_CLASA_H
#define OOP_CLASA_H
#pragma once
#include <string>
#include "Catalog.h"  // Include the Catalog header because Clasa uses the Catalog class
template<typename Student>
class Clasa {
private:
    std::string numeClasa;
    Catalog<Student>& catalog;  // Reference to Catalog
    std::vector<Materie*> materii;

    

public:
    Clasa( const std::string &numeClasa,   Catalog<Student>& catalog);
    Clasa( const Clasa &clasa);
    Clasa& operator=(const Clasa& other);
    double calculeazaMediaGenerala() const;
    std::string getNumeClasa() const;
    void simuleazaZiDeScoala();
    void checkAndPerformActivity(const Person* person);

    const  Catalog<Student> &getCatalog() const;
};


#endif //OOP_CLASA_H
