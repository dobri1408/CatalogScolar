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
    Catalog& catalog;  // Reference to Catalog
    std::vector<Materie*> materii;

    

public:
    Clasa( std::string numeClasa,  Catalog catalog);
    Clasa& operator=(const Clasa& other);

    friend void swap(Clasa& a, Clasa& b) noexcept {
        using std::swap; // Enable ADL
        // Explicitly swap all members
        swap(a.materii, b.materii);
        swap(a.catalog, b.catalog);
        swap(a.numeClasa, b.numeClasa);
        // Add more swaps for other members
    }


    double calculeazaMediaGenerala() const;
    std::string getNumeClasa() const;
    void simuleazaZiDeScoala();
    void checkAndPerformActivity(const Person* person);

    const Catalog &getCatalog() const;
};


#endif //OOP_CLASA_H
