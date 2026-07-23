//
// Created by rzv on 7/11/26.
//

#include "Car.h"

#include <iostream>
#include  <vector>
#include <string>
#include "Driver.h"
//constructor
Car::Car(const std::string& tipcombustibil,
         const std::string& sas,
         const std::string& nr,
         const std::string& ma,
         const std::string& mo,
         int km,
         double cap,
         const std::string& Caroserie,
         int Locuri,
         double consum,
         std::chrono::sys_days ITP,
         std::chrono::sys_days RCA)
: RoadVehicle(tipcombustibil, sas, ma, mo, cap, nr, km, ITP, RCA), tipCaroserie(Caroserie), nrLocuri(Locuri), consumMediu(consum) {
    //nimic acum
}

//destructor
Car::~Car() {
    //nimic
}

//metode si getteri
double Car::calculeazaConsum(int km) {return (km * consumMediu) / 100;}
int Car::calculeazaAutonomie() {return nivelCombustibilCurent/consumMediu * 100;}
void Car::inregistreazaCursa(int km) {
    if (calculeazaAutonomie() < km) {
        std::cout << "Combustibilul nu ajunge pentru aceasta cursa!" << std::endl;
        return;
    }
    double lirii_consumati = calculeazaConsum(km);
    consuma(lirii_consumati);
    this->kilometraj += km;
}
bool Car::permisValid(const Driver &d) {
    std::vector<std::string> p = d.get_permis();
    for (std::string s : p) {
        if (s == "B")
            return true;
    }
    return false;
}

std::string Car::get_tipCaroserie() const {return tipCaroserie;}
int Car::get_nrLocuri() const {return nrLocuri;}
double Car::get_consumMediu() const {return consumMediu;}
