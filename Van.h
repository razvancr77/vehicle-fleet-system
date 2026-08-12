//
// Created by rzv on 8/11/26.
//

#ifndef FLOTAAUTO_VAN_H
#define FLOTAAUTO_VAN_H

#include "RoadVehicle.h"

class Van : public RoadVehicle {
    private:
    double capacitateMarfaKilograme;
    double incarcaturaCurenta;

    public:
    //constructor
    Van(const std::string& combustibil,
        const std::string& sasiu,
        const std::string& marca,
        const std::string& model,
        double cap,
        const std::string& nrInmatriculare,
        int kilometraj,
        std::chrono::sys_days dataITP,
        std::chrono::sys_days dataRCA,
        double capMarfa,
        double consum,
        int km_ultima_revizie);
    //destructor
    ~Van();

    //getter
    double get_capacitateMarfa() const;

    //metode pur virtuale
    bool permisValid(const Driver &d) override;
    double calculeazaConsum(int kilometri) override;
    int calculeazaAutonomie() override;
    int limitaRevizie() override;

    //metode specifice dubei
    void descarcaMarfa();
    bool incarcaMarfa(double kg);
};
#endif //FLOTAAUTO_VAN_H