//
// Created by rzv on 8/11/26.
//

#include "Van.h"
#include "Driver.h"
#include "Exceptions.h"
#include <vector>
#include <stdexcept>

//constructor
Van::Van(const std::string& combustibil,
        const std::string& sasiu,
        const std::string& marca,
        const std::string& model,
        double capRez,
        const std::string& nrInmatriculare,
        int kilometraj,
        std::chrono::sys_days dataITP,
        std::chrono::sys_days dataRCA,
        double capMarfa,
        double consum,
        int revizie)
            : RoadVehicle(combustibil, sasiu, marca, model, capRez, nrInmatriculare, kilometraj, dataITP, dataRCA, consum, revizie), capacitateMarfaKilograme(capMarfa) {
    this->incarcaturaCurenta = 0.0;
}

//destructor
Van::~Van() {
    //nimic
}

//getter
double Van::get_capacitateMarfa() const {return this->capacitateMarfaKilograme;}

//metode
void Van::descarcaMarfa() {this->incarcaturaCurenta = 0.0;}

void Van::incarcaMarfa(double kg) {
    if (kg <= 0) {
        throw std::invalid_argument("Trebuie incarcata marfa cu valoare pozitiva.");
    }

    double greutateTotala = this->incarcaturaCurenta + kg;
    if (greutateTotala > this->capacitateMarfaKilograme) {
        throw VanWeightException("Nu se poate incarca cu o greutate asa de mare.");
    }

    this->incarcaturaCurenta = greutateTotala;
}



//implementarea metodelor pur virtuale
bool Van::permisValid(const Driver &d) {
    std::vector<std::string> p = d.get_permis();
    for (std::string s : p) {
        if (s == "C" || s == "B")//dube si mai mici de 3.5 tone si mai grele de atat
            return true;
    }
    return false;
}

double Van::calculeazaConsum(int kilometri) {
    //adaugam 0.5 L la consumul mediu pentru fiecare 100 de kg incarcate
    double consumReal = consumMediu + (incarcaturaCurenta / 100.0) * 0.5;
    return (kilometri / 100.0) * consumReal;
}

int Van::calculeazaAutonomie() {
    double consumReal = consumMediu + (incarcaturaCurenta / 100.0) * 0.5;
    return this->nivelCombustibilCurent / consumReal * 100;
}

int Van::limitaRevizie() {return 10000;}
