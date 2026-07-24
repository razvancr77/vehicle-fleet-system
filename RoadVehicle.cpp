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
                         std::chrono::sys_days dataRCA)
: Vehicle(combustibil,sasiu,marca,model,cap), nrInmatriculare(nrInmatriculare), kilometraj(kilometraj), dataExpirareITP(dataITP), dataExpirareRCA(dataRCA){
    //nimic aici
}

RoadVehicle::~RoadVehicle() {
    //nimic
}

//metode
int RoadVehicle::get_kilometraj() const {return kilometraj;}
std::string RoadVehicle::get_nrInmatriculare() const {return nrInmatriculare;}

bool RoadVehicle::evalueazaStare() {
    if (expired(this->dataExpirareITP)) return false;
    if (expired(this->dataExpirareRCA)) return false;
    //alte verificari
    return true;
}

bool RoadVehicle::necesitaITP() const {
    return expires_in_chunk_time(this->dataExpirareITP);
}

bool RoadVehicle::necesitaRCA() const {
    return expires_in_chunk_time(this->dataExpirareRCA);
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






