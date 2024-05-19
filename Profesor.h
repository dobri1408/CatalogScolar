//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_PROFESOR_H
#define OOP_PROFESOR_H
#pragma once
#include "Person.h"
#include <vector>
#include <string>

class Profesor : public Person {
private:
     std::vector< std::pair<std::string,  std::string>> concedii_medicale;  // Subjects the professor teaches
    std::vector<std::string>subjects;

public:
    Profesor(const std::string &name, const std::string &email);

    Profesor(const Profesor &other);

    Profesor &operator=(const Profesor &other);

    virtual ~Profesor();

    bool esteProfesorulInConcediu() const;


    std::string getDescription() const override;
    void suntBolnav()  const override;


};
#endif //OOP_PROFESOR_H
