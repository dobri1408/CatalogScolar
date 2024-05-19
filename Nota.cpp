#include "Nota.h"

Nota::Nota() :materie(),valoare(0) {}

Nota::Nota(Materie* &materie, const int &valoare) : materie(materie), valoare(valoare) {}

Nota::Nota(const Nota& other) : materie(other.materie), valoare(other.valoare) {}

Nota& Nota::operator=(const Nota& other) {
    if (this != &other) {
        materie = other.materie;
        valoare = other.valoare;
    }
    return *this;
}

Nota::~Nota() {}

int Nota::getValoare() const {
    return valoare;
}

Materie* Nota::getMaterie() const {
    return materie;
}

std::ostream& operator<<(std::ostream& os, const Nota& n) {
    os << n.materie->getMaterie() << " " << n.valoare;
    return os;
}
