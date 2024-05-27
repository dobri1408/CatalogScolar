//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_NOTA_H
#define OOP_NOTA_H
#pragma once
#include "Materie.h"  // Include Materie as Nota uses it


template <typename T>
class Nota {
private:
    Materie* materie;
    T valoare;

public:
    Nota();
    Nota(Materie* materie, const T &valoare);
    Nota(const Nota& other);
    Nota& operator=(const Nota<T>& other);
    ~Nota();

    T getValoare() const;
    Materie* getMaterie() const;

    friend std::ostream& operator<<(std::ostream& os, const Nota<int>& n);
    friend std::ostream& operator<<(std::ostream& os, const Nota<std::string>& n);
};

#endif //OOP_NOTA_H
