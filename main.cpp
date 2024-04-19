#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Parinte {
private:
    string nume;
    string email;

public:
    Parinte(){}
    Parinte(const string nume, const string email) : nume(nume), email(email) {}

    // Constructor de copiere
    Parinte(const Parinte& other) : nume(other.nume), email(other.email) {}

    // Operator de copiere
    Parinte& operator=(const Parinte& other) {
        if (this != &other) {
            nume = other.nume;
            email = other.email;
        }
        return *this;
    }

    ~Parinte() {}

    bool areParinte(){
        return nume.size()>0 && email.size()>0;
    }

    void trimiteEmail(const string& informatia) {
        cout << "Trimitere email la " << email << ": " << informatia << endl;
    }
};

class Materie {
private:
    string numeMaterie;
    string profesor;

public:
	Materie(){}
    Materie(const string &numeMaterie, const string &profesor) : numeMaterie(numeMaterie), profesor(profesor) {}
    Materie(const Materie& other) : numeMaterie(other.numeMaterie), profesor(other.profesor) {}
    Materie& operator=(const Materie& other) {
        if (this != &other) {
            numeMaterie = other.numeMaterie;
            profesor = other.profesor;
        }
        return *this;
    }
    ~Materie() {}
     
    const string& getMaterie() const { return numeMaterie; }

    friend ostream& operator<<(ostream& os, const Materie& m) {
        os << "Materie: " << m.numeMaterie << ", Profesor: " << m.profesor;
        return os;
    }
};

class Nota {
private:
    Materie materie;
    int valoare;

public:
	Nota(){}
    Nota(Materie &materie, const int &valoare) : materie(materie), valoare(valoare) {}
    Nota(const Nota& other) : materie(other.materie), valoare(other.valoare) {}
    Nota& operator=(const Nota& other) {
        if (this != &other) {
            materie = other.materie;
            valoare = other.valoare;
        }
        return *this;
    }
    ~Nota() {}
    int getValoare() const { return valoare; }
    Materie getMaterie() const { return materie; }
  
    friend ostream& operator<<(ostream& os, const Nota& n) {
        os << n.materie << ", Nota: " << n.valoare;
        return os;
    }
};

// Clasa Student
class Student {
private:
    string nume;
    string prenume;
    int id;
    vector<Nota> note;  // Array dinamic de note
    size_t numarNote;
    Parinte p;

public:
    Student(const string &nume, const string &prenume, const Parinte &p, const int &id) : nume(nume), prenume(prenume), id(id), note(vector<Nota>()), numarNote(0),p(p) {}

    // Constructor pentru initializarea notelor
    Student(const string &nume, const string &prenume, const int &id, const vector<Nota> &noteArray, const size_t &numarNote) : nume(nume), prenume(prenume), id(id), numarNote(numarNote), note(noteArray) {
       
    }

    // Constructor de copiere
    Student(const Student& other) : nume(other.nume), prenume(other.prenume), id(other.id), numarNote(other.numarNote),note(other.note) {
        
    }

    // Operator de atribuire
    Student& operator=(const Student& other) {
        if (this != &other) {
            nume = other.nume;
            prenume = other.prenume;
            id = other.id;

            numarNote = other.numarNote;
            note = other.note;
        }
        return *this;
    }

    // Destructor
    ~Student() {
       note.resize(0);
        cout << "Distrug Student: " << nume << " " << prenume << endl;
    }
     void adaugaNota(const Nota& nota) {
        note.push_back(nota);
        if(p.areParinte()){
            p.trimiteEmail(nume + " " + prenume + "a primit o nota: " +  to_string(nota.getValoare()) + " la " + nota.getMaterie().getMaterie());
        }
    }

    const string getNumeComplet() const {
        return (string)nume + (string)" " + (string)prenume;
    }

	  double calculeazaMedia() const {
        if (note.empty()) return 0.0;
        double suma = 0.0;
        for (const auto& nota : note) {
            suma += nota.getValoare();
        }
        return suma / note.size();
    }

    bool esteCorigent() const {
        return calculeazaMedia() < 5;
        }
 
    

    int notaMaxima() const {
        int max = 0;
        for (const auto& nota : note) {
            if (nota.getValoare() > max) {
                max = nota.getValoare();
            }
        }
        return max;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        os << "ID: " << s.id << ", Nume: " << s.nume << ", Prenume: " << s.prenume;
        if (s.note.size()>0) {
            os << ", Note: ";
            for (size_t i = 0; i < s.note.size(); i++) {
                os << s.note[i] << " ";
            }
        }
        return os;
    }
};

// Clasa Materie

// Clasa Nota

// Clasa Catalog
class Catalog {
private:
    vector<Student> studenti;

public:
    void adaugaStudent(const Student& student) {
        studenti.push_back(student);
    }
    void afiseazaTopulClasei() {
        sort(studenti.begin(), studenti.end(), [](const Student& s1, const Student& s2) {
            return s1.calculeazaMedia() > s2.calculeazaMedia();
        });

        for (auto& student : studenti) {
            cout << student.getNumeComplet()<< " - Media: " << student.calculeazaMedia() << endl;
        }
    }
    void afiseazaCatalog() {
        for (auto& student : studenti) {
            cout << student << endl;
        }
       
    }
    void afiseazaCorigentii() {
        cout << "Studentii corigenti sunt:" << endl;
        for (const auto& student : studenti) {
            if (student.esteCorigent()) {
                cout << student.getNumeComplet() << endl;
            }
        }
    }
};

int main() {
    Student s1("Ion", "Popescu",Parinte("Alex","alex@gmail.com"), 1);
    Materie m1("Matematica", "Pop Ion");
       Materie m2("Romana", "Pop Ion");
    Nota n1(m1, 9);

    Catalog catalog;
        s1.adaugaNota(Nota(m1, 9));
    s1.adaugaNota(Nota(m1, 10));
    s1.adaugaNota(Nota(m2, 4));
    catalog.adaugaStudent(s1);
    catalog.afiseazaCatalog();
    catalog.afiseazaCorigentii();


    cout << s1 << endl;
    cout << "Media notelor: " << s1.calculeazaMedia() << endl;
    cout << "Corigent: " << (s1.esteCorigent() ? "Da" : "Nu") << endl;
    cout << "Nota maxima: " << s1.notaMaxima() << endl;
    catalog.afiseazaTopulClasei();
    return 0;
}
