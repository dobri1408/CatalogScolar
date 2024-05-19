#include "Clasa.h"
#include "Nota.h"
#include "Person.h"
#include <random>

int generateRandom() {
    std::random_device rd;  // Generator de numere aleatorii bazat pe hardware
    std::mt19937 gen(rd()); // Motor de numere aleatorii bazat pe algoritmul Mersenne Twister
    std::bernoulli_distribution dist(0.7); // Distribuție Bernoulli cu p = 0.7 pentru probabilitatea de 1

    return dist(gen); // Returnează 0 sau 1, unde 1 are o probabilitate de 70%
}
Clasa::Clasa( std::string numeClasa,  Catalog catalog)
        : numeClasa(numeClasa), catalog(catalog) {}

 double Clasa::calculeazaMediaGenerala() const {
    return catalog.calculeazaMediaGenerala();
}

Clasa& Clasa::operator=(const Clasa& other) {
    if (this != &other) {
        // Correctly handle copyable members
        this->numeClasa = other.numeClasa;

        // Can't rebind references; might log or handle differently
        // References and unique_ptr cannot be reassigned, manage accordingly
        // You might need to rethink your design if you find yourself needing to assign to a class with a reference member.
    }
    return *this;
}
std::string Clasa::getNumeClasa() const {
    return numeClasa;
}

void Clasa::checkAndPerformActivity(const Person* person) {

    const Student* st = dynamic_cast<const Student*>(person);
    if (st) {
            if(generateRandom()==0) //"cu sanse de 30 la suta s-a imbolnavit studentul"
            {
                st->suntBolnav();
            }
    } else {
       const Profesor* professor = dynamic_cast<const Profesor*>(person);
        if (professor) {
            for (auto &materie: materii) {
                // Here, make sure that getProfesor() returns a Profesor* and that getDescription is valid
                if (professor->getDescription() == materie->getProfesor()->getDescription()) {
                    for (auto &student : catalog.returnStudents()) {
                        // Make sure you properly access the dereferenced materie and handle Nota correctly.
                        student.adaugaNota(Nota( materie,10));
                    }
                }
            }
        }
    }
}


void Clasa::simuleazaZiDeScoala(){

    for(const auto& personal: catalog.getPersonal()){
        checkAndPerformActivity(personal.get());
    }

}

const Catalog &Clasa::getCatalog() const {
    return catalog;
}
