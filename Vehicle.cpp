//
// Created by rzv on 7/9/26.
//

#include "Vehicle.h"
#include "Exceptions.h"
#include <iostream>
//constructor
Vehicle::Vehicle(const std::string& combustibil, const std::string& sasiu, const std::string& marca, const std::string& model, double capRez) : serieSasiu(sasiu), marca(marca), model(model), combustibil(combustibil), capacitateRezervor(capRez) {
    this->sofer = nullptr;
    this->nivelCombustibilCurent = 0.0;
    this->activ = true;
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
bool Vehicle::isActiv() const {return this->activ;}



//metode
void Vehicle::asigneazaSofer(Driver *angajat) {
    if(!this->activ) {
        throw InactiveVehicleException("Statusul vehicului este inactiv!");
    }

    if (angajat == nullptr ) {
        throw std::invalid_argument("Pointerul catre sofer este null!");
    }

    if (this->sofer != nullptr) {
        throw VehicleOccupiedException("Vehiculul are deja asignat un sofer! Daca vreti sa contunuati trebuie sa eliberati mai intai vechiul sofer.");
    }

    if (!permisValid(*angajat)) {
        throw DriverLicenseException("Acest angajat nu are categoria de permis necesara conducerii acestui vehicul.");
    }

    this->sofer = angajat;
}

void Vehicle::elibereazaSofer() {
    this->sofer = nullptr;
}


void Vehicle::alimenteaza(double litrii) {
    if (litrii <= 0 ) {
        throw std::invalid_argument("Cantitatea trebuie sa fie pozitiva!");
    }
    if(litrii + nivelCombustibilCurent > this->capacitateRezervor) {
        throw FuelCapacityException("Se depaseste capacitatea rezervorului!");
    }
    this->nivelCombustibilCurent += litrii;
}

void Vehicle::consuma(double litrii) {
    if (litrii <= 0) {
        throw std::invalid_argument("Cantitatea trebuie sa fie pozitiva!");
    }


    if (nivelCombustibilCurent - litrii < 0) {
        throw FuelCapacityException("Nu se pot consuma atat de multi litrii de combustibil(se goleste rezervorul)");
    }
    this->nivelCombustibilCurent -= litrii;
}





