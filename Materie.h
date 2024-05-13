#ifndef OOP_MATERIE_H
#define OOP_MATERIE_H

#pragma once
#include <string>
#include <iostream>
#include "Profesor.h"

class Materie {
private:
    std::string numeMaterie;
    Profesor* profesor; // Now using Profesor class instead of std::string


public:
    Materie();
    Materie(const std::string &numeMaterie,  Profesor* &profesor);
    Materie(const Materie& other);
    Materie& operator=(const Materie& other);
    ~Materie();

    const std::string& getMaterie() const;
    const Profesor* getProfesor() const;  // Provide access to the Profesor

    friend std::ostream& operator<<(std::ostream& os, const Materie& m);
};

#endif // OOP_MATERIE_H
