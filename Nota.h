//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_NOTA_H
#define OOP_NOTA_H
#pragma once
#include "Materie.h"  // Include Materie as Nota uses it

class Nota {
private:
    Materie* materie;
    int valoare;

public:
    Nota();
    Nota(Materie* &materie, const int &valoare);
    Nota(const Nota& other);
    Nota& operator=(const Nota& other);
    ~Nota();

    int getValoare() const;
    Materie* getMaterie() const;

    friend std::ostream& operator<<(std::ostream& os, const Nota& n);
};

#endif //OOP_NOTA_H
