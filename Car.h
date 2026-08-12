//
// Created by rzv on 7/11/26.
//

#ifndef FLOTAAUTO_CAR_H
#define FLOTAAUTO_CAR_H

#include <string>
#include "RoadVehicle.h"

class Car : public RoadVehicle {
    private:
    std::string tipCaroserie;
    int nrLocuri;

    public:
    //constructor
    Car(const std::string& tipcombustibil,
        const std::string& serieSas,
        const std::string& nrInmatric,
        const std::string& Marca,
        const std::string& Model,
        int kilometraj,
        double capRez,
        const std::string& Caroserie,
        int Locuri,
        std::chrono::sys_days dataITP,
        std::chrono::sys_days dataRCA,
        double consumMediu,
        int km_ultima_revizie);
    ~Car();
    //metode virtuale
    double calculeazaConsum(int kilometri) override;//cati litrii de combustibil s-au consumat pe distanta
    bool permisValid(const Driver &d) override;
    int calculeazaAutonomie() override;
    int limitaRevizie() override;

    //geterii
    std::string get_tipCaroserie() const;
    int get_nrLocuri() const;
    double get_consumMediu() const;
};
#endif //FLOTAAUTO_CAR_H