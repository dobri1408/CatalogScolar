#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


    struct BarChartStruct{
        string name;
        double value;
    };


    class BarChart{
    private:
        vector<BarChartStruct> result;
        string title;
        int size;
        double height;
        double maxNum;
        int count;

        auto getMaxValue(vector<BarChartStruct> input){

            double max = 0;
            for (auto& i: input){
                if (i.value > max){
                    max = i.value;
                }
            }

            return max;

        }

        void numString(int num, int ma){
            string n = to_string(num);
            string mn = to_string(ma);

            int c = n.size();
            int mc = mn.size();

            if (c < mc){

                for (int i = 0; i < mc - c; i++) cout<<"0";

            }
            cout<<n;
        }

    public:
        BarChart(const string &title, int size, int count, const vector<BarChartStruct> &result){

            this->title = title;
            this->size = size;

            this->result = result;
            this->count = count;


            this->maxNum = getMaxValue(result);

            this->height = maxNum / this->count;




        }

        void show(){
            int x_width = (int)this->result.size() * this->size;


            cout<<"====[ "<<this->title<<" ]";
            for (int z = 0; z < x_width * 2; z++) cout<<"=";
            cout<<endl;
            cout<<endl;
            int maxGap = to_string(this->maxNum).size();

            for (auto& r: this->result){

                for (int w = 0; w < maxGap; w++) cout<<" ";
                cout<<"| "<<r.name<<" : "<<r.value;
                if (r.value == this->maxNum) cout<<" √ (Max)"<<endl;
                else cout<<endl;

            }

            cout<<endl;
            for (double y = 0; y < this->height; y++){
                numString((this->height - y) * this->count, this->maxNum);
                numString(-(this->height - y) * this->count-1, this->maxNum);
                cout<<"| ";
                for (int x = 0; x < x_width; x++){
                    if (x % size == 0){
                        int index = x / size;
                        double value = this->result[index].value;

                        if (this->height - y <= (double)(value / this->count)){
                            cout<<"▩▩▩"; //
                        }else{
                            cout<<"   ";
                        }
                    }else{
                        cout<<"   ";
                    }
                }
                cout<<endl;
            }
            for (int i = 0;i < x_width + 10; i++) cout<<"▬▬▬";
            cout<<endl;
            for (int a = 0;a < 10; a++){
                cout<<"  ";
                for (int w = 0; w < 3; w++) cout<<" ";
                for (int i = 0;i < x_width; i++){
                    if (i % size == 0){

                        string n = this->result[i / size].name;

                        if (a < (int)n.size()){

                            cout<<" "<<n[a]<<" ";

                        }else{
                            cout<<"   ";
                        }

                    }else{
                        cout<<"   ";
                    }
                }
                cout<<endl;
            }
            cout<<endl;
        }
    };



class Parinte {
private:
    string nume;
    string email;

public:
    Parinte(){}
    Parinte(const string &nume, const string &email) : nume(nume), email(email) {}

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

    bool isDataSet(){
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
    Parinte parinte;

public:
    Student(const string &nume, const string &prenume, const Parinte &p, const int &id) : nume(nume), prenume(prenume), id(id), note(vector<Nota>()),parinte(p) {}

    // Constructor pentru initializarea notelor
    Student(const string &nume, const string &prenume, const int &id, const vector<Nota> &noteArray) : nume(nume), prenume(prenume), id(id), note(noteArray) {
       
    }

    // Constructor de copiere
    Student(const Student& other) : nume(other.nume), prenume(other.prenume), id(other.id),note(other.note) {
        
    }

    // Operator de atribuire
    Student& operator=(const Student& other) {
        if (this != &other) {
            nume = other.nume;
            prenume = other.prenume;
            id = other.id;
            note = other.note;
        }
        return *this;
    }

    // Destructor
    ~Student() {
       note.resize(0);

    }
     void adaugaNota(const Nota& nota) {
        note.push_back(nota);
        if(parinte.isDataSet()){
            parinte.trimiteEmail(nume + " " + prenume + "a primit o nota: " +  to_string(nota.getValoare()) + " la " + nota.getMaterie().getMaterie());
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
     double calculeazaMediaGenerala() {
        if (studenti.empty()) return 0.0;
        double sumaMediilor = 0.0;
        for (auto& student : studenti) {
            sumaMediilor +=student.calculeazaMedia();
            }
        return sumaMediilor / studenti.size();
    }
};
class Clasa {
private:
    string numeClasa;
    Catalog catalog;
public:
    Clasa(const string &numeClasa,const Catalog &catalog) : numeClasa(numeClasa), catalog(catalog) {}
     double calculeazaMediaGenerala() {
        return catalog.calculeazaMediaGenerala();
    }

     string getNumeClasa() const {
        return numeClasa;
    }

};

class Scoala {
private:
    string numeScoala;
    vector<Clasa> clase;
public:
    explicit Scoala(const string &numeScoala) : numeScoala(numeScoala) {}
    void adaugaClasa(const Clasa& clasa) {
        clase.emplace_back(clasa);
        cout << "Clasa " << clasa.getNumeClasa() << " a fost adaugata la scoala " << numeScoala << "." << endl;
    }
    vector<BarChartStruct> sorteazaClaseDupaMedie() {
        vector<BarChartStruct> claseSortate;
        sort(clase.begin(), clase.end(), [](Clasa a,  Clasa& b) {
            return a.calculeazaMediaGenerala() > b.calculeazaMediaGenerala();
        });
       for (auto c:clase){
           claseSortate.push_back({c.getNumeClasa(),c.calculeazaMediaGenerala()});
       }
       return claseSortate;
    }
};
int main() {
    // Define subjects
    Materie matematica("Matematica", "Ionescu Maria");
    Materie romana("Romana", "Georgescu Ion");
    Materie fizica("Fizica", "Popescu Elena");
    Materie chimie("Chimie", "Dumitru George");
    Materie istorie("Istorie", "Vasilescu Dan");
    Materie geografie("Geografie", "Marinescu Laura");

    // Define parents
    Parinte parent1("Popescu Elena", "elena.popescu@gmail.com");
    Parinte parent2("Ionescu Marius", "marius.ionescu@yahoo.com");
    Parinte parent3("Vasilescu Ana", "ana.vasilescu@outlook.com");

    // Create students for class 12B
    Student s1("Ion", "Popescu", parent1, 1);
    Student s2("Maria", "Ionescu", parent2, 2);
    Student s3("Dan", "Vasilescu", parent3, 3);

    // Create students for class 11A
    Student s4("Laura", "Marinescu", parent1, 4);
    Student s5("George", "Matei", parent2, 5);
    Student s6("Elena", "Dumitru", parent3, 6);

    cout << "Nota maxima: " << s1.notaMaxima() << endl;
    // Add grades to students in class 12B
    s1.adaugaNota(Nota(matematica, 9));
    s1.adaugaNota(Nota(romana, 10));
    s2.adaugaNota(Nota(fizica, 8));
    s2.adaugaNota(Nota(chimie, 7));
    s3.adaugaNota(Nota(istorie, 10));
    s3.adaugaNota(Nota(geografie, 10));

    // Add grades to students in class 11A
    s4.adaugaNota(Nota(matematica, 8));
    s4.adaugaNota(Nota(romana, 7));
    s5.adaugaNota(Nota(fizica, 10));
    s5.adaugaNota(Nota(chimie, 9));
    s6.adaugaNota(Nota(istorie, 5));
    s6.adaugaNota(Nota(geografie, 6));

    // Create catalogs for each class
    Catalog catalog12B;
    Catalog catalog11A;

    // Add students to catalogs
    catalog12B.adaugaStudent(s1);
    catalog12B.adaugaStudent(s2);
    catalog12B.adaugaStudent(s3);
    catalog11A.adaugaStudent(s4);
    catalog11A.adaugaStudent(s5);
    catalog11A.adaugaStudent(s6);

    // Create school
    Scoala sc("Colegiul National ICHB");

    // Add classes to the school
    sc.adaugaClasa(Clasa("12B", catalog12B));
    sc.adaugaClasa(Clasa("11A", catalog11A));

    // Display school statistics
    cout << "Catalogul clasei 12B:" << endl;
    catalog12B.afiseazaCatalog();
    cout << "Catalogul clasei 11A:" << endl;
    catalog11A.afiseazaCatalog();

    cout << "Studentii corigenti din 12B:" << endl;
    catalog12B.afiseazaCorigentii();
    cout << "Studentii corigenti din 11A:" << endl;
    catalog11A.afiseazaCorigentii();

    cout << "Topul clasei 12B dupa medie:" << endl;
    catalog12B.afiseazaTopulClasei();
    cout << "Topul clasei 11A dupa medie:" << endl;
    catalog11A.afiseazaTopulClasei();

    cout << "Media generala a clasei 12B: " << Clasa("12B", catalog12B).calculeazaMediaGenerala() << endl;
    cout << "Media generala a clasei 11A: " << Clasa("11A", catalog11A).calculeazaMediaGenerala() << endl;

    // Generate and show a bar chart of class averages in the school
    auto claseSortate = sc.sorteazaClaseDupaMedie();
    BarChart clasaChart("Clasele dupa medie", 2, 1, claseSortate);
    clasaChart.show();

    return 0;
}