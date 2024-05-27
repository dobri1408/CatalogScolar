//
// Created by Dobricean Ioan Dorian on 27.05.2024.
//

#include "SistemNationalCatalog.h"

#include "ElevPrimar.h"
#include "Scoala.h"  // Includes Clasa, which in turn should include Catalog if set up correctly
#include "Catalog.h"  // Includes Student and Nota if set up correctly
#include "Clasa.h"
#include "ElevGimnaziu.h"
#include "Nota.h"
#include "Parinte.h"  // Only include if you directly use Parinte in main
#include "Materie.h"  // Only include if you directly use Materie in main
#include "Profesor.h"
#include "Director.h"
#include "CatalogFactory.h"
#include "BarchartProxy.h"
#include <variant>
SistemNationalCatalog::SistemNationalCatalog(const std::vector<Scoala> &scoli) : scoli(scoli) {}

SistemNationalCatalog::SistemNationalCatalog() {}



void SistemNationalCatalog::CreeeazaUnScenariuInitial(){
    auto professor =   std::make_unique<Profesor>("Alice Johnson", "alice@example.com");
    auto professor2 =   std::make_unique<Profesor>("Alice Mark", "alice@example.com");
    professor->suntBolnav(); //virtual function
    Materie* m1 =new Materie("",professor.get());
    delete m1;

    auto matematica = std::make_unique<Materie>("Matematica", professor.get());
    auto romana = std::make_unique<Materie>("Romana", professor.get());
    auto fizica = std::make_unique<Materie>("Fizica", professor2.get());
    auto chimie = std::make_unique<Materie>("Chimie", professor2.get());
    auto istorie = std::make_unique<Materie>("Istorie", professor2.get());
    auto geografie = std::make_unique<Materie>("Geografie", professor2.get());
    auto engleza = std::make_unique<Materie>("Engleza", professor.get());
    auto pictura = std::make_unique<Materie>("Pictura", professor.get());
    auto tehnologie = std::make_unique<Materie>("Tehnologie", professor.get());




    // Define parents
    Parinte parent1("Popescu Elena", "elena.popescu@gmail.com");
    Parinte parent2("Ionescu Marius", "marius.ionescu@yahoo.com");
    Parinte parent3("Vasilescu Ana", "ana.vasilescu@outlook.com");

    // Create students for class 12B
    ElevGimnaziu s1("Ion", "email", parent1, 1);
    ElevGimnaziu s2("Maria", "email", parent2, 2);
    ElevGimnaziu s3("Dan", "email", parent3, 3);

    // Create students for class 11A
    ElevGimnaziu s4("Laura", "email", parent1, 4);
    ElevGimnaziu s5("George", "email", parent2, 5);
    ElevGimnaziu s6("Elena", "email", parent3, 6);
    ElevPrimar s7("Miruna","email",parent3,10);

    std::cout << "Nota maxima: " << s1.notaMaxima() << std::endl;
    s1.suntBolnav();
    // Add grades to students in class 12B
    s1.adaugaNota(Nota(matematica.get(), 9));
    s1.adaugaNota(Nota(romana.get(), 10));
    s2.adaugaNota(Nota(fizica.get(), 10));
    s2.adaugaNota(Nota(chimie.get(), 10));
    s3.suntBolnav(); // virtual function
    s3.adaugaNota(Nota(istorie.get(), 10));
    s3.adaugaNota(Nota(geografie.get(), 10));

    s7.adaugaNota(Nota(tehnologie.get(), std::string("FB")));

    // Add grades to students in class 11A
    s4.adaugaNota(Nota(matematica.get(), 8));
    s4.adaugaNota(Nota(romana.get(), 10));
    s5.adaugaNota(Nota(fizica.get(), 10));
    s5.adaugaNota(Nota(chimie.get(), 9));
    s6.adaugaNota(Nota(istorie.get(), 10));
    s6.adaugaNota(Nota(geografie.get(), 6));

    //  Create catalogs for each class

    auto catalog12B = std::get<Catalog<ElevGimnaziu>>(CatalogFactory::createCatalog("12B"));
    auto catalog11A = std::get<Catalog<ElevGimnaziu>>(CatalogFactory::createCatalog("11A"));
    auto catalog4A = std::get<Catalog<ElevPrimar>>(CatalogFactory::createCatalog("4A"));

    catalog4A.adaugaStudent(s7);
    // Add students to catalogs
    catalog12B.adaugaStudent(s1);

    catalog12B.adaugaStudent(s2);
    catalog12B.adaugaStudent(s3);
    catalog11A.adaugaStudent(s4);
    catalog11A.adaugaStudent(s5);
    catalog11A.adaugaStudent(s6);

    std::vector<std::unique_ptr<Materie>> smartMaterii;
    std::vector<std::unique_ptr<Materie>> smartMaterii2;
    std::vector<std::unique_ptr<Materie>> smartMaterii3;

// Add unique_ptr directly, using std::move to transfer ownership
    smartMaterii.push_back(std::move(matematica));
    smartMaterii.push_back(std::move(romana));
    smartMaterii.push_back(std::move(geografie));

    smartMaterii2.push_back(std::move(pictura));
    smartMaterii2.push_back(std::move(engleza));

    smartMaterii3.push_back(std::move(tehnologie));

// Usage of these vectors in your school system, for example:
    try {
        catalog12B.adaugaMateriileObligatorii(std::move(smartMaterii));
    } catch (const std::exception& e) {
        std::cerr << "A aparut o eroare: " << e.what() << std::endl;
    }

    try {
        catalog11A.adaugaMateriileObligatorii(std::move(smartMaterii2));
    }
    catch (const std::exception& e)
    {
        std::cerr << "A aparut o eroare: " << e.what() << std::endl;
    }

    try {
        catalog4A.adaugaMateriileObligatorii(std::move(smartMaterii3));
    }
    catch (const std::exception& e)
    {
        std::cerr << "A aparut o eroare: " << e.what() << std::endl;
    }

    // Create school
    Scoala sc("Colegiul National ICHB");
    Scoala sc2("Colegiul National Vianu");
    Scoala sc3("Scoala Primara Bucuresti");
//    sc.adaugaMembru(professor);

    // Add classes to the school
    sc.adaugaClasa(Clasa("12B", catalog12B));
    sc2.adaugaClasa(Clasa("11A", catalog11A));
    sc3.adaugaClasa(Clasa("4A", catalog4A));

    // Display school statistics
    std::cout << "Catalogul clasei 12B:" << std::endl;
    catalog12B.afiseazaCatalog(std::cout);
    std::cout << "Catalogul clasei 11A:" <<  std::endl;
    catalog11A.afiseazaCatalog(std::cout);

    std::cout << "Studentii corigenti din 12B:" <<  std::endl;
    catalog12B.afiseazaCorigentii();
    std::cout << "Studentii corigenti din 11A:" <<  std::endl;
    catalog11A.afiseazaCorigentii();

    std::cout << "Topul clasei 12B dupa medie:" <<  std::endl;
    catalog12B.afiseazaTopulClasei();
    std::cout << "Topul clasei 11A dupa medie:" <<  std::endl;
    catalog11A.afiseazaTopulClasei();

   std:: cout << "Media generala a clasei 12B: " << Clasa("12B", catalog12B).calculeazaMediaGenerala() <<  std::endl;
   std:: cout << "Media generala a clasei 11A: " << Clasa("11A", catalog11A).calculeazaMediaGenerala() <<  std::endl;

    // Generate and show a bar chart of class averages in the school
    sc.simuleazaZiDeScoala();
    sc2.simuleazaZiDeScoala();
    sc3.simuleazaZiDeScoala();


    auto claseSortate = sc.getRank();

    BarChartProxy clasaChart("Clasele dupa medie", 2, 1, claseSortate);
    clasaChart.show();
    auto claseSortate2 = sc2.getRank();
    BarChartProxy clasaChart2("Clasele dupa medie", 2, 1, claseSortate2);
    //clasaChart.show();
    //clasaChart2.show();
    std::cout <<" Creare fisiere csv\n";
    Director director = Director(*professor,sc);
    if(director.verificaCalitatea()==true){
        std::cout<<"Directorul este competent";
    }
    else std::cout<<"Directorul nu este competent";

    clasaChart.show();
    sc.exportCSV();


    clasaChart2.show();
    sc2.exportCSV();
    scoli.push_back(sc);
    scoli.push_back(sc2);
    scoli.push_back(sc3);

}