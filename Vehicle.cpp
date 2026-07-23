//
// Created by rzv on 7/9/26.
//

#include "Vehicle.h"
#include <iostream>
//constructor
Vehicle::Vehicle(const std::string& combustibil, const std::string& sasiu, const std::string& marca, const std::string& model, double cap) : combustibil(combustibil), serieSasiu(sasiu), marca(marca), model(model), capacitateRezervor(cap) {
    this->sofer = nullptr;
    this->nivelCombustibilCurent = 0.0;
}

//destructor
Vehicle::~Vehicle() {
    //momentan nimic
}

//getterii
std::string Vehicle::get_serieSasiu() const {return this->serieSasiu;}
std::string Vehicle::get_marca() const {return this->marca;}
std::string Vehicle::get_model() const {return this->model;}
std::string Vehicle::get_combustibil() const {return this->combustibil;}
Driver *Vehicle::get_sofer() const {return this->sofer;}
double Vehicle::get_capacitateRezervor() const {return this->capacitateRezervor;}
double Vehicle::get_nivelCombusibilCurent() const {return this->nivelCombustibilCurent;}


//metode
bool Vehicle::asigneazaSofer(Driver *angajat) {
    if (angajat == nullptr || this->sofer != nullptr) return false;

    bool conform = permisValid(*angajat);
    if (conform) {
        this->sofer = angajat;
        return true;
    }
    std::cout << "Acest angajat nu are categoria de permis necesara conducerii acestui vehicul." << std::endl;
    return false;
}

void Vehicle::elibereazaSofer() {
    this->sofer = nullptr;
}


void Vehicle::alimenteaza(double litrii) {
    if (litrii < 0 || litrii + nivelCombustibilCurent > this->capacitateRezervor) {
        std::cout << "Numarul de litrii nu e adecvat pentru alimentare." << std::endl;
        return;
    }
    this->nivelCombustibilCurent += litrii;
}

void Vehicle::consuma(double litrii) {
    if (litrii < 0 || nivelCombustibilCurent - litrii < 0) {
        std::cout << "Numarul de litrii consumati nu are cum sa fie reali" << std::endl;
    }
    this->nivelCombustibilCurent -= litrii;
}





