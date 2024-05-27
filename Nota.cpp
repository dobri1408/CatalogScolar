#include "Nota.h"
#include <type_traits>
#include <iostream>
#include <string>

template<typename T>
Nota<T>::Nota() :materie(),valoare() {}

template<typename T>
Nota<T>::Nota(Materie* materie, const T &valoare) : materie(materie), valoare(valoare) {}
template<typename T>
Nota<T>::Nota(const Nota& other) : materie(other.materie), valoare(other.valoare) {}
template<typename T>
Nota<T>& Nota<T>::operator=(const Nota<T>& other) {
    if (this != &other) {
        materie = other.materie;
        valoare = other.valoare;
    }
    return *this;
}
template<typename T>
Nota<T>::~Nota() {}
template<typename T>
T Nota<T>::getValoare() const {
    return valoare;
}
template<typename T>
Materie* Nota<T>::getMaterie() const {
    return materie;
}


std::ostream& operator<<(std::ostream& os, const Nota<int>& n) {
    if (n.getMaterie() == nullptr) {
        os << "Unknown Materie ";
    } else {
        os << n.getMaterie() << " ";
    }
    os << n.getValoare();
    return os;
}


std::ostream& operator<<(std::ostream& os, const Nota<std::string>&  n) {
    if (n.getMaterie() == nullptr) {
        os << "Unknown Materie ";
    } else {
        os << n.getMaterie() << " ";
    }
    for(auto s:n.getValoare())
        os << s;

    return os;
}






template class Nota<int>;
template class Nota<std::string>;


