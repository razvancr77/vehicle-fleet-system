//
// Created by rzv on 7/14/26.
//

#include "RoadVehicle.h"
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



