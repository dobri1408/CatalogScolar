#include "Catalog.h"
#include "Exceptions.h"
void Catalog::adaugaStudent(const Student& student) {
    studenti.push_back(student);
    personal.push_back(new Student(student));
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
std::vector<Student> Catalog::returnStudents() {
    return studenti;
}

std::vector<Person*> Catalog::getPersonal() {
    return personal;
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
    }
    return sumaMediilor / studenti.size();
}

void Catalog::adaugaMateriileObligatorii(std::vector<Materie*> v) {

    if(v.size()>16){
        throw SchoolAdminException("Prea multe materii");

    }
    for(auto materie:v){
        personal.push_back(const_cast<Person*>(static_cast<const Person*>(materie->getProfesor())));

    }
    materii = v;
}

Catalog::~Catalog() {
    for (auto student : personal) {
        delete student;
    }
}
