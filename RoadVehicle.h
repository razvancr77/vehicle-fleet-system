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
    bool acteValabile() const;

    protected:
    std::string nrInmatriculare;
    int kilometraj;
    double consumMediu;
    std::chrono::sys_days dataExpirareITP;//data(care e concentrata pe zile doar) cand expira ITP -ul vehiculului
    std::chrono::sys_days dataExpirareRCA;
    int km_ultima_revizie;

    public:
    RoadVehicle(const std::string& combustibil,
                const std::string& sasiu,
                const std::string& marca,
                const std::string& model,
                double cap,
                const std::string& nrInmatriculare,
                int kilometraj,
                std::chrono::sys_days dataITP,
                std::chrono::sys_days dataRCA,
                double consumMediu,
                int ultimaRevizie);
    virtual ~RoadVehicle();

    //getterii
    std::string get_nrInmatriculare() const;
    int get_kilometraj() const;
    std::chrono::sys_days get_dataExpirareITP() const;
    std::chrono::sys_days get_dataExpirareRCA() const;

    //metode pur virtuale
    virtual double calculeazaConsum(int kilometri) = 0;
    virtual int limitaRevizie() = 0;

    //metode
    int zileITP() const;//cate zile pana la expirare
    int zileRCA() const;
    void actualizeazaITP(std::chrono::sys_days newDate);
    void actualizeazaRCA(std::chrono::sys_days newDate);
    void inregistreazaCursa(int km);
    void efectueazaRevizie();
    int km_pana_la_revizie();
};
#endif //FLOTAAUTO_ROADVEHICLE_H