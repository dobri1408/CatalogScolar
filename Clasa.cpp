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
template<typename Student>
Clasa<Student>::Clasa(const std::string& numeClasa,  Catalog<Student>& catalog)
        : numeClasa(numeClasa), catalog(catalog) {}

template<typename Student>
 double Clasa<Student>::calculeazaMediaGenerala() const {
    return catalog.calculeazaMediaGenerala();
}
template<typename Student>
Clasa<Student>::Clasa(const Clasa<Student> &other)
        : numeClasa(other.numeClasa),  // Initialize `numeClasa` directly from `other.numeClasa`
          catalog(other.catalog)      // Initialize `catalog` directly from `other.catalog`
{
    // Constructor body is now empty since initialization is handled above
}
template<typename Student>
Clasa<Student>& Clasa<Student>::operator=(const Clasa<Student>& other) {
    if (this != &other) {
        // Correctly handle copyable members
        this->numeClasa = other.numeClasa;
        this->catalog = other.catalog;
    }
    return *this;
}
template<typename Student>
std::string Clasa<Student>::getNumeClasa() const {
    return numeClasa;
}
template<typename Student>
void Clasa<Student>::checkAndPerformActivity(const Person* person) {

    const Student* st = dynamic_cast<const Student*>(person);
    if (st) {
            if(generateRandom()==0) //"cu sanse de 30 la suta sa invete studentul"
            {
              std::cout <<"Invat\n";
            }
    } else {
        const Profesor* professor = dynamic_cast<const Profesor*>(person);
        if (professor) {
            for (auto &materie: materii) {
                if (professor->getDescription() == materie->getProfesor()->getDescription()) {
                    for (auto &student : catalog.returnStudents()) {
                        if constexpr (std::is_same_v<Student, ElevGimnaziu>) {
                            student.adaugaNota(Nota<int>(materie, 10));
                        } else if constexpr (std::is_same_v<Student, ElevPrimar>) {
                            student.adaugaNota(Nota<std::string>(materie, "FB"));
                        }
                    }
                }
            }
        }
    }

}

template<typename Student>
void Clasa<Student>::simuleazaZiDeScoala(){

    for(const auto& personal: catalog.getPersonal()){
        checkAndPerformActivity(personal.get());
    }

}
template<typename Student>
const Catalog<Student> &Clasa<Student>::getCatalog() const {
    return catalog;
}
template class Catalog<ElevGimnaziu>;
template class Catalog<ElevPrimar>;
template class Clasa<ElevPrimar>;
template class Clasa<ElevGimnaziu>;
template class Nota<int>;
template class Nota<std::string>;