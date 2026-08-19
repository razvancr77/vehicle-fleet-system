//
// Created by rzv on 7/14/26.
//

#include "RoadVehicle.h"
#include "TimeUtils.h"
#include "Exceptions.h"
#include <stdexcept>
#include <iostream>
//constructor
RoadVehicle::RoadVehicle(const std::string& combustibil,
                         const std::string& sasiu,
                         const std::string& marca,
                         const std::string& model,
                         double cap,
                         const std::string& nrInmatriculare,
                         int kilometraj,
                         std::chrono::sys_days dataITP,
                         std::chrono::sys_days dataRCA,
                         double consum,
                         int ultimaRevizie)
: Vehicle(combustibil,sasiu,marca,model,cap), nrInmatriculare(nrInmatriculare), kilometraj(kilometraj), dataExpirareITP(dataITP), dataExpirareRCA(dataRCA), consumMediu(consum), km_ultima_revizie(ultimaRevizie){
    //nimic aici
}

RoadVehicle::~RoadVehicle() {
    //nimic
}

//getterii
int RoadVehicle::get_kilometraj() const {return kilometraj;}
std::string RoadVehicle::get_nrInmatriculare() const {return nrInmatriculare;}
std::chrono::sys_days RoadVehicle::get_dataExpirareITP() const {return this->dataExpirareITP;}
std::chrono::sys_days RoadVehicle::get_dataExpirareRCA() const {return this->dataExpirareRCA;}



//metode
bool RoadVehicle::acteValabile() const { //e privata
    if (expired(this->dataExpirareITP)) return false;
    if (expired(this->dataExpirareRCA)) return false;
    //alte verificari
    return true;
}

int RoadVehicle::zileITP() const {
    return days_until_expiration(this->dataExpirareITP);
}

int RoadVehicle::zileRCA() const {
    return days_until_expiration(this->dataExpirareRCA);
}

void RoadVehicle::actualizeazaITP(std::chrono::sys_days newDate) {
    std::chrono::sys_days azi = current_day();
    if (newDate < azi) {
        throw std::invalid_argument("Noua data de expirare nu poate fi din trecut!");
    }
    this->dataExpirareITP = newDate;
    this->activ = acteValabile();
}

void RoadVehicle::actualizeazaRCA(std::chrono::sys_days newDate) {
    std::chrono::sys_days azi = current_day();
    if (newDate < azi) {
        throw std::invalid_argument("Noua data de expirare nu poate fi din trecut!");
    }
    this->dataExpirareRCA = newDate;
    this->activ = acteValabile();
}

void RoadVehicle::inregistreazaCursa(int km) {
    this->activ = acteValabile();

    if(!this->activ) {
        throw InactiveVehicleException("Statusul vehicului este inactiv!");
    }

    if (km <= 0) {
        throw std::invalid_argument("Kilometrii parcursi trebuie sa fie > 0.");
    }

    if (calculeazaAutonomie() < km) {
        throw FuelCapacityException("Combustibilul nu ajunge pentru aceasta cursa!");
    }

    double lirii_consumati = calculeazaConsum(km);
    consuma(lirii_consumati);
    this->kilometraj += km;
}

void RoadVehicle::efectueazaRevizie() {this->km_ultima_revizie = this->kilometraj;}

int RoadVehicle::km_pana_la_revizie() {return this->limitaRevizie() - (this->kilometraj - this->km_ultima_revizie);}






