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
         std::chrono::sys_days ITP,
         std::chrono::sys_days RCA,
         double consum)
: RoadVehicle(tipcombustibil, sas, ma, mo, cap, nr, km, ITP, RCA, consum), tipCaroserie(Caroserie), nrLocuri(Locuri) {
    //nimic acum
}

//destructor
Car::~Car() {
    //nimic
}

//metode si getteri
double Car::calculeazaConsum(int km) {return (km * consumMediu) / 100;}
int Car::calculeazaAutonomie() {return nivelCombustibilCurent/consumMediu * 100;}
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
