//
// Created by rzv on 8/11/26.
//

#include "Van.h"
#include "Driver.h"
#include <vector>

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
        double consum)
            : RoadVehicle(combustibil, sasiu, marca, model, capRez, nrInmatriculare, kilometraj, dataITP, dataRCA, consum), capacitateMarfaKilograme(capMarfa) {
    this->incarcaturaCurenta = 0.0;
}

//destructor
Van::~Van() {
    //nimic
}

//getter
double Van::get_capacitateMarfa() const {return this->capacitateMarfaKilograme;}

void Van::descarcaMarfa() {this->incarcaturaCurenta = 0.0;}

bool Van::incarcaMarfa(double kg) {
    double greutateTotala = this->incarcaturaCurenta + kg;
    if (greutateTotala > this->capacitateMarfaKilograme)
        return false;
    this->incarcaturaCurenta = greutateTotala;
    return true;
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
