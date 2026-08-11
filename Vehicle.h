//
// Created by rzv on 7/9/26.
//

#ifndef FLOTAAUTO_VEHICLE_H
#define FLOTAAUTO_VEHICLE_H

#include <string>


class Driver;

class Vehicle {
protected:
    std::string serieSasiu;
    std::string marca;//BMW
    std::string model;//X3
    std::string combustibil;
    Driver *sofer;
    double capacitateRezervor;
    double nivelCombustibilCurent;
    bool activ;

public:
    Vehicle( const std::string& combustibil,
             const std::string& sasiu,
             const std::string& marca,
             const std::string& model,
             double capRezervor);
    virtual ~Vehicle();
    //getterii
    std::string get_serieSasiu() const;
    std::string get_marca() const;
    std::string get_model() const;
    std::string get_combustibil() const;
    Driver *get_sofer() const;
    double get_capacitateRezervor() const;
    double get_nivelCombusibilCurent() const;
    bool isActiv() const;

    virtual bool permisValid(const Driver& d) = 0;
    virtual int calculeazaAutonomie() = 0;

    //metode mostenite direct
    bool asigneazaSofer(Driver *angajat);
    void elibereazaSofer();
    void alimenteaza(double litrii);
    void consuma(double litrii);
};
#endif //FLOTAAUTO_VEHICLE_H