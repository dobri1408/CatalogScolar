//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_CATALOG_H
#define OOP_CATALOG_H
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Student.h"  // Include the Student class header

class Catalog {
private:
    std::vector<Student> studenti;
    std::vector<Materie*>materii;
    std::vector<Person*> personal;
public:
    virtual ~Catalog();

    void adaugaStudent(const Student& student);
    void afiseazaTopulClasei();
    void afiseazaCatalog(std::ostream& fout);
    void afiseazaCorigentii();
    void adaugaMateriileObligatorii(std::vector<Materie*> v);
    std::vector<Person*> getPersonal();
    double calculeazaMediaGenerala() const;
    std::vector<Student>returnStudents();
};

#endif //OOP_CATALOG_H
