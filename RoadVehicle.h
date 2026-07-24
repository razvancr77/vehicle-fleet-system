//
// Created by rzv on 7/14/26.
//

#ifndef FLOTAAUTO_ROADVEHICLE_H
#define FLOTAAUTO_ROADVEHICLE_H
#include "Vehicle.h"
#include <chrono>
#define DAYS_BEFORE_EXPIRATION 30

class RoadVehicle : public Vehicle {
    private:
    bool evalueazaStare();
    protected:
    std::string nrInmatriculare;
    int kilometraj;
    std::chrono::sys_days dataExpirareITP;//data(care e concentrata pe zile doar) cand expira ITP -ul vehiculului
    std::chrono::sys_days dataExpirareRCA;


    public:
    RoadVehicle(const std::string& combustibil,
                const std::string& sasiu,
                const std::string& marca,
                const std::string& model,
                double cap,
                const std::string& nrInmatriculare,
                int kilometraj,
                std::chrono::sys_days dataITP,
                std::chrono::sys_days dataRCA);
    virtual ~RoadVehicle();

    //getterii
    std::string get_nrInmatriculare() const;
    int get_kilometraj() const;
    //metode pur virtuale
    virtual double calculeazaConsum(int kilometri) = 0;
    virtual void inregistreazaCursa(int km) = 0;

    //metode
    bool necesitaITP() const;
    bool necesitaRCA() const;
    void actualizeazaITP(std::chrono::sys_days newDate);
    void actualizeazaRCA(std::chrono::sys_days newDate);
};
#endif //FLOTAAUTO_ROADVEHICLE_H