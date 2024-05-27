#include "Catalog.h"
#include "Exceptions.h"

template<typename Student>
Catalog<Student>::Catalog() {

}
template<typename Student>
void Catalog<Student>::afiseazaTopulClasei() {
    std::sort(studenti.begin(), studenti.end(), [](const Student& s1, const Student& s2) {
        return s1.calculeazaMedia() > s2.calculeazaMedia();
    });

    for (auto& student : studenti) {
        std::cout << student.getDescription() << " - Media: " << student.calculeazaMedia() << std::endl;
    }
}
template<typename Student>
const void Catalog<Student>::afiseazaCatalog(std::ostream& fout) const {
    for (auto& student : studenti) {
        fout << student << std::endl;
    }
}
template<typename Student>
std::vector<Student> Catalog<Student>::returnStudents() const{
    return studenti;
}
template<typename Student>
std::vector<std::shared_ptr<const Person>> Catalog<Student>::getPersonal() const {
    return personal;  // Assuming 'personal' is defined as std::vector<std::shared_ptr<const Person>>
}

template<typename Student>
void Catalog<Student>::afiseazaCorigentii() {
    std::cout << "Studentii corigenti sunt:" << std::endl;
    for (const auto& student : studenti) {
        if (student.esteCorigent()) {
            std::cout << student.getDescription() << std::endl;
        }
    }
}
template<typename Student>
double Catalog<Student>::calculeazaMediaGenerala() const {

    if (studenti.empty()) return 0.0;
    if (std::is_same<Student, ElevPrimar>::value)
            return 0.0;
    double sumaMediilor = 0.0;

    for (auto& student : studenti) {

        sumaMediilor += student.calculeazaMedia();

    }
    return sumaMediilor / studenti.size();
}
template<typename Student>
Catalog<Student>::Catalog( const Catalog<Student>& other) {
    for (const auto& materie : other.materii) {
        materii.push_back(std::make_unique<Materie>(*materie));
    }for (const auto& pers : other.personal) {
        personal.push_back(pers);
    }
    for (const auto& student : other.studenti) {
        studenti.push_back(student);
    }
}
template<typename Student>
Catalog<Student>& Catalog<Student>::operator=(const Catalog<Student>& other) {
    if (this != &other) {
        materii.clear();
        for (const auto& materie : other.materii) {
            materii.push_back(std::make_unique<Materie>(*materie));
        }

        for (const auto& student : other.studenti) {
            studenti.push_back(student);
        }
        personal.clear();
        for (const auto& pers : other.personal) {
            personal.push_back(pers);
        }
    }
    return *this;
}
template<typename Student>
void Catalog<Student>::adaugaStudent(const Student& student) {
    studenti.push_back(Student(student));

    // Create a shared_ptr for the student to be added to the personal list
    personal.push_back(std::make_shared<Student>(student));
}
template<typename Student>
void Catalog<Student>::adaugaMateriileObligatorii(std::vector<std::unique_ptr<Materie>>&& v) {
    if (v.size() > 16) {
        throw SchoolAdminException("Prea multe materii");
    }


    for (auto& materie : v) {
        if (materie == nullptr) {
            // Handle or skip null unique_ptrs
            continue;
        }

        // Access Profesor before moving the unique_ptr
        const Profesor* profesor = materie->getProfesor();
        if (profesor != nullptr) {
            std::shared_ptr<const Profesor> profesor_ptr(profesor, [](const Profesor*){ /* no-op deleter */ });
            personal.push_back(std::static_pointer_cast<const Person>(profesor_ptr));
        } else {
            // Handle the case where no valid Profesor is associated
        }

        // Now move the unique_ptr safely after extracting necessary info
        materii.push_back(std::move(materie));
    }
}

template class Catalog<ElevGimnaziu>;
template class Catalog<ElevPrimar>;