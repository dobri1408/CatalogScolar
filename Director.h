//
// Created by Dobricean Ioan Dorian on 21.05.2024.
//

#ifndef OOP_DIRECTOR_H
#define OOP_DIRECTOR_H
#include "Scoala.h"

class Director : public Profesor  {
private:
    Scoala scoala;
public:
    Director(const Profesor &other, const Scoala &scoala);
    bool verificaCalitatea();
};


#endif //OOP_DIRECTOR_H
