#include "Catalog.h"
#include "Exceptions.h"

Catalog::Catalog() {
    // Implementare, dacă este necesară inițializarea specială
}
void Catalog::afiseazaTopulClasei() {
    std::sort(studenti.begin(), studenti.end(), [](const Student& s1, const Student& s2) {
        return s1.calculeazaMedia() > s2.calculeazaMedia();
    });

    for (auto& student : studenti) {
        std::cout << student.getDescription() << " - Media: " << student.calculeazaMedia() << std::endl;
    }
}

void Catalog::afiseazaCatalog(std::ostream& fout) {
    for (auto& student : studenti) {
        fout << student << std::endl;
    }
}
std::vector<Student> Catalog::returnStudents() const{
    return studenti;
}

std::vector<std::shared_ptr<const Person>> Catalog::getPersonal() const {
    return personal;  // Assuming 'personal' is defined as std::vector<std::shared_ptr<const Person>>
}


void Catalog::afiseazaCorigentii() {
    std::cout << "Studentii corigenti sunt:" << std::endl;
    for (const auto& student : studenti) {
        if (student.esteCorigent()) {
            std::cout << student.getDescription() << std::endl;
        }
    }
}

double Catalog::calculeazaMediaGenerala() const {

    if (studenti.empty()) return 0.0;
    double sumaMediilor = 0.0;

    for (auto& student : studenti) {
        sumaMediilor += student.calculeazaMedia();
        std::cout <<"NHM"<<student.calculeazaMedia();
    }
    return sumaMediilor / studenti.size();
}

Catalog::Catalog(const Catalog& other) {
    for (const auto& materie : other.materii) {
        materii.push_back(std::make_unique<Materie>(*materie));
    }for (const auto& pers : other.personal) {
        personal.push_back(pers);
    }
    for (const auto& student : other.studenti) {
        studenti.push_back(student);
    }
}
Catalog& Catalog::operator=(const Catalog& other) {
    if (this != &other) {
        materii.clear();
        for (const auto& materie : other.materii) {
            materii.push_back(std::make_unique<Materie>(*materie));
        }
        studenti.clear();
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

void Catalog::adaugaStudent(const Student& student) {
    studenti.push_back(Student(student));

    // Create a shared_ptr for the student to be added to the personal list
    personal.push_back(std::make_shared<Student>(student));
}

void Catalog::adaugaMateriileObligatorii(std::vector<std::unique_ptr<Materie>>&& v) {
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

