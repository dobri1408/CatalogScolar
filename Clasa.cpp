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
Clasa::Clasa(const std::string &numeClasa, const Catalog &catalog)
        : numeClasa(numeClasa), catalog(catalog) {}

const double Clasa::calculeazaMediaGenerala() const {
    return catalog.calculeazaMediaGenerala();
}

std::string Clasa::getNumeClasa() const {
    return numeClasa;
}

void Clasa::checkAndPerformActivity(Person* person) {

    Student* student = dynamic_cast<Student*>(person);
    if (student) {
            if(generateRandom()==0) //"cu sanse de 30 la suta s-a imbolnavit studentul"
            {
                student->suntBolnav();
            }
    } else {
        Profesor* professor = dynamic_cast<Profesor*>(person);
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

    for(auto personal: catalog.getPersonal()){
        checkAndPerformActivity(personal);
    }

}