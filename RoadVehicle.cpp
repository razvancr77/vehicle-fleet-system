//
// Created by rzv on 7/14/26.
//

#include "RoadVehicle.h"
#include "TimeUtils.h"
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
bool RoadVehicle::evalueazaStare() {
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
        std::cout << "Noua data de expirare e din trecut!" << std::endl;
        return;
    }
    this->dataExpirareITP = newDate;
    this->activ = evalueazaStare();
}

void RoadVehicle::actualizeazaRCA(std::chrono::sys_days newDate) {
    std::chrono::sys_days azi = current_day();
    if (newDate < azi) {
        std::cout << "Noua data de expirare e din trecut!" << std::endl;
        return;
    }
    this->dataExpirareRCA = newDate;
    this->activ = evalueazaStare();
}

void RoadVehicle::inregistreazaCursa(int km) {
    if(!this->activ) {
        std::cout << "Statusul vehicului este inactiv!" << std::endl;
        return;
    }
    if (calculeazaAutonomie() < km) {
        std::cout << "Combustibilul nu ajunge pentru aceasta cursa!" << std::endl;
        return;
    }
    double lirii_consumati = calculeazaConsum(km);
    consuma(lirii_consumati);
    this->kilometraj += km;
}

void RoadVehicle::efectueazaRevizie() {this->km_ultima_revizie = this->kilometraj;}

int RoadVehicle::km_pana_la_revizie() {return this->limitaRevizie() - (this->kilometraj - this->km_ultima_revizie);}






