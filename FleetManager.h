//
// Created by rzv on 8/27/26.
//

#ifndef FLOTAAUTO_FLEETMANAGER_H
#define FLOTAAUTO_FLEETMANAGER_H

class Driver;
class Vehicle;

#include <memory>
#include <vector>

class FleetManager {
private:
    std::vector<std::unique_ptr<Driver>> soferi;
    std::vector<std::unique_ptr<Vehicle>> vehicule;

public:
    //constructor
    FleetManager();
    //destructor
    ~FleetManager();
    //metode
    void adaugaVehicul(std::unique_ptr<Vehicle> autovehicul);
    void adaugaSofer(std::unique_ptr<Driver> sofer);
    void stergeVehicul(const std::string& nrInmatriculare);
    void deplasareVehicul(const std::string& nrInmatriculare, int km);
    void asigneazaSofer(const std::string& nrInmatriculare, const std::string& cnpSofer);
    void elibereazaSofer(const std::string& nrInmatriculare);
    void alimenteazaVehicul(const std::string& nrInmatriculare, double litri);
    void efectueazaRevizie(const std::string& nrInmatriculare);
    void incarcaMarfaDuba(double kg);
    void descarcaMarfaDuba();
    double estimeazaCostCursa(const std::string& nrInmatriculare, int km, double pretLitru);
    void pornesteMeniu();
    // METODE DE VIZUALIZARE
    void afiseazaFlota() const;
    void afiseazaSoferi() const;
    void afiseazaAlerteMentenanta() const;
    void reinnoiesteITP(const std::string& nrInmatriculare, int an, int luna, int zi);
    void reinnoiesteRCA(const std::string& nrInmatriculare, int an, int luna, int zi);
    void afiseazaAlerteRevizii() const;
};

#endif //FLOTAAUTO_FLEETMANAGER_H