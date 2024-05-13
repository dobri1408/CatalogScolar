#include "Materie.h"
#include "Exceptions.h"

Materie::Materie() : numeMaterie(""), profesor(new Profesor("","")) {}

Materie::Materie(const std::string &numeMaterie,  Profesor* &profesor)
        : numeMaterie(numeMaterie), profesor(profesor) {
    try{
    if (numeMaterie.empty()) {
        throw InvalidMaterieException("Numele materiei nu poate fi gol.");
    }}catch (const std::exception& e)
    {
        std::cerr << "A aparut o eroare: " << e.what() << std::endl;
    }
}

Materie::Materie(const Materie& other)
        : numeMaterie(other.numeMaterie), profesor(other.profesor) {}

Materie& Materie::operator=(const Materie& other) {
    if (this != &other) {
        numeMaterie = other.numeMaterie;
        profesor = other.profesor;
    }
    return *this;
}

Materie::~Materie() {}

const std::string& Materie::getMaterie() const {
    return numeMaterie;
}
 const Profesor* Materie::getProfesor() const {
    return profesor;
}

std::ostream& operator<<(std::ostream& os, const Materie& m) {
    os << "Materie: " << m.numeMaterie << ", Profesor: " << m.profesor->getDescription();
    return os;
}
