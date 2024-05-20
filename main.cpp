#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#include "Scoala.h"  // Includes Clasa, which in turn should include Catalog if set up correctly
#include "Catalog.h"  // Includes Student and Nota if set up correctly
#include "Clasa.h"
#include "Student.h"
#include "Nota.h"
#include "Parinte.h"  // Only include if you directly use Parinte in main
#include "Materie.h"  // Only include if you directly use Materie in main
#include "Profesor.h"
#include "SchoolAPI.h"


using namespace std;



int main() {
    // Define subjects
    Profesor* professor =  new Profesor("Alice Johnson", "alice@example.com");
    Profesor* professor2 =  new Profesor("Alice Mark", "alice@example.com");
    professor->suntBolnav(); //virtual function
    Materie* m1 =new Materie("",professor);
    delete m1;

    Materie* matematica = new Materie("Matematica",  professor);
    Materie* romana =  new Materie("Romana",  professor);
    Materie*fizica= new Materie("Fizica",  professor2);
    Materie* chimie= new Materie("Chimie",  professor2);
    Materie* istorie=new Materie("Istorie",  professor2);
    Materie* geografie=new Materie("Geografie", professor2);
    Materie* engleza = new Materie("Engleza",  professor);
    Materie* pictura =  new Materie("Pictura",  professor);


    // Define parents
    Parinte parent1("Popescu Elena", "elena.popescu@gmail.com");
    Parinte parent2("Ionescu Marius", "marius.ionescu@yahoo.com");
    Parinte parent3("Vasilescu Ana", "ana.vasilescu@outlook.com");

    // Create students for class 12B
    Student s1("Ion", "email", parent1, 1);
    Student s2("Maria", "email", parent2, 2);
    Student s3("Dan", "email", parent3, 3);

    // Create students for class 11A
    Student s4("Laura", "email", parent1, 4);
    Student s5("George", "email", parent2, 5);
    Student s6("Elena", "email", parent3, 6);

    cout << "Nota maxima: " << s1.notaMaxima() << endl;
    s1.suntBolnav();
    // Add grades to students in class 12B
    s1.adaugaNota(Nota(matematica, 9));
    s1.adaugaNota(Nota(romana, 10));
    s2.adaugaNota(Nota(fizica, 10));
    s2.adaugaNota(Nota(chimie, 10));
    s3.suntBolnav(); // virtual function
    s3.adaugaNota(Nota(istorie, 10));
    s3.adaugaNota(Nota(geografie, 10));

    // Add grades to students in class 11A
    s4.adaugaNota(Nota(matematica, 8));
    s4.adaugaNota(Nota(romana, 10));
    s5.adaugaNota(Nota(fizica, 10));
    s5.adaugaNota(Nota(chimie, 9));
    s6.adaugaNota(Nota(istorie, 10));
    s6.adaugaNota(Nota(geografie, 6));

   //  Create catalogs for each class
    Catalog catalog12B;
    Catalog catalog11A;

    // Add students to catalogs
    catalog12B.adaugaStudent(s1);

    catalog12B.adaugaStudent(s2);
    catalog12B.adaugaStudent(s3);
    catalog11A.adaugaStudent(s4);
    catalog11A.adaugaStudent(s5);
    catalog11A.adaugaStudent(s6);

    std::vector<Materie*> materii;
    materii.push_back(matematica);
    materii.push_back(romana);
    materii.push_back(geografie);
    std::vector<Materie*> materii2;
    materii2.push_back(pictura);
    materii2.push_back(engleza);

    std::vector<std::unique_ptr<Materie>> smartMaterii;
    std::vector<std::unique_ptr<Materie>> smartMaterii2;
    smartMaterii.reserve(materii.size());  // Reserve space to avoid multiple allocations
    smartMaterii2.reserve(materii2.size());  // Reserve space to avoid multiple allocations
    for (Materie* m : materii) {
        smartMaterii.push_back(std::unique_ptr<Materie>(m));
    }
    for (Materie* m : materii2) {
        smartMaterii2.push_back(std::unique_ptr<Materie>(m));
    }
//
    try {
        catalog12B.adaugaMateriileObligatorii(std::move(smartMaterii));

    }catch (const std::exception& e)
    {
        std::cerr << "A aparut o eroare: " << e.what() << std::endl;
    }
    try {


       // catalog12B.adaugaMateriileObligatorii( std::move(smartMaterii2));

    }catch (const std::exception& e)
    {
        std::cerr << "A aparut o eroare: " << e.what() << std::endl;
    }

    // Create school
    Scoala sc("Colegiul National ICHB");
    Scoala sc2("Colegiul National Vianu");
//    sc.adaugaMembru(professor);

    // Add classes to the school
    sc.adaugaClasa(Clasa("12B", catalog12B));
    sc2.adaugaClasa(Clasa("11A", catalog11A));

    // Display school statistics
    cout << "Catalogul clasei 12B:" << endl;
    catalog12B.afiseazaCatalog(cout);
    cout << "Catalogul clasei 11A:" << endl;
    catalog11A.afiseazaCatalog(cout);

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
    sc.simuleazaZiDeScoala();
    sc2.simuleazaZiDeScoala();


    auto claseSortate = sc.getRank();

    BarChart clasaChart("Clasele dupa medie", 2, 1, claseSortate);
//    clasaChart.show();
    auto claseSortate2 = sc2.getRank();
    BarChart clasaChart2("Clasele dupa medie", 2, 1, claseSortate2);
//    clasaChart2.show();
    std::cout <<" Creare fisiere csv\n";

        clasaChart.show();
        sc.exportCSV();


        clasaChart2.show();
        sc2.exportCSV();



    return 0;
}