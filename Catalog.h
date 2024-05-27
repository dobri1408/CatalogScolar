// Created by Dobricean Ioan Dorian on 10.05.2024.

#ifndef OOP_CATALOG_H
#define OOP_CATALOG_H
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>  // Include for smart pointers
#include "ElevGimnaziu.h"  // Include the Student class header
#include "ElevPrimar.h"  // Include the Student class header


template<typename Student>
class Catalog {
private:
    std::vector<Student> studenti;
    std::vector<std::unique_ptr<Materie>> materii;  // Using unique_ptr for exclusive ownership
    std::vector<std::shared_ptr<const Person>> personal;  // Using shared_ptr for shared ownership

public:


    Catalog( const Catalog& other);
    Catalog();
    Catalog& operator=(const Catalog& other);
    void adaugaStudent(const Student& student);
    void afiseazaTopulClasei();
    void afiseazaCatalog(std::ostream& fout) const;
    void afiseazaCorigentii();
    void adaugaMateriileObligatorii(std::vector<std::unique_ptr<Materie>>&& v);
    std::vector<std::shared_ptr<const Person>> getPersonal() const;  // Return shared pointers
    double calculeazaMediaGenerala() const;
    std::vector<Student> returnStudents() const;
};

#endif //OOP_CATALOG_H
