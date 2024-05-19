//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_PARINTE_H
#define OOP_PARINTE_H
#pragma once
#include <string>
#include "Person.h"
#include <iostream>

class Parinte : public Person{

public:
    Parinte(const std::string &name, const std::string &email);
    Parinte(const Parinte &other);
    Parinte();
    Parinte& operator=(const Parinte &other);
    virtual ~Parinte();

    bool isDataSet();
    std::string getDescription() const override;  // Ensure this is declared to override
     void suntBolnav()  const override;  // Ensure this is declared to override
};

#endif //OOP_PARINTE_H
