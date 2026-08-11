#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <chrono>

// Include headerele proiectului
#include "Car.h"
#include "Driver.h"
#include "TimeUtils.h"

// Funcție ajutătoare pentru a converti An, Lună, Zi introduse de la tastatură într-o dată reală C++20
std::chrono::sys_days creeazaData(int an, int luna, int zi) {
    return std::chrono::sys_days(std::chrono::year_month_day{
        std::chrono::year{an},
        std::chrono::month{static_cast<unsigned>(luna)},
        std::chrono::day{static_cast<unsigned>(zi)}
    });
}

int main() {
    // Flota noastră de mașini
    std::vector<std::unique_ptr<Car>> flota;

    // Creăm doi șoferi predefiniți pentru a ușura testarea
    std::vector<std::unique_ptr<Driver>> soferi;
    soferi.push_back(std::make_unique<Driver>("Popescu Ion", "1900101123456", std::vector<std::string>{"B", "C"}));
    soferi.push_back(std::make_unique<Driver>("Ionescu Ana", "2950505123456", std::vector<std::string>{"B"}));

    int optiune;
    bool ruleaza = true;

    std::cout << "=== BINE ATI VENIT IN SISTEMUL DE GESTIUNE HOLVER ===" << std::endl;

    while (ruleaza) {
        std::cout << "\n--- MENIU PRINCIPAL ---" << std::endl;
        std::cout << "1. Afiseaza toate vehiculele" << std::endl;
        std::cout << "2. Adauga un vehicul nou (Car)" << std::endl;
        std::cout << "3. Sterge un vehicul" << std::endl;
        std::cout << "4. Asigneaza sofer pe o masina" << std::endl;
        std::cout << "5. Elibereaza sofer de pe o masina" << std::endl;
        std::cout << "6. Inregistreaza o cursa (adauga KM)" << std::endl;
        std::cout << "7. Alimenteaza o masina" << std::endl;
        std::cout << "8. Dashboard Mentenanta (Verifica alerte ITP/RCA)" << std::endl;
        std::cout << "9. Reinnoieste ITP / RCA pentru o masina" << std::endl;
        std::cout << "0. Iesire din sistem" << std::endl;
        std::cout << "Alege o optiune: ";
        std::cin >> optiune;

        switch (optiune) {
            case 1: {
                std::cout << "\n--- FLOTA ACTUALA (" << flota.size() << " masini) ---" << std::endl;
                if (flota.empty()) {
                    std::cout << "Flota este goala!" << std::endl;
                } else {
                    for (std::size_t i = 0; i < flota.size(); i++) {
                        std::cout << i << ". Masina [Activ: " << (flota[i]->isActiv() ? "DA" : "NU") << "]";
                        std::cout << " | ITP ramas: " << flota[i]->zileITP() << " zile";
                        std::cout << " | RCA ramas: " << flota[i]->zileRCA() << " zile" << std::endl;
                    }
                }
                break;
            }
            case 2: {
                std::string tipCombustibil, serieSas, nrInmatric, marca, model, caroserie;
                int kilometraj, locuri;
                double capRez, consum;
                int anITP, lunaITP, ziITP;
                int anRCA, lunaRCA, ziRCA;

                std::cout << "Tip combustibil (ex: Benzina/Diesel): "; std::cin >> tipCombustibil;
                std::cout << "Serie sasiu (VIN): "; std::cin >> serieSas;
                std::cout << "Numar inmatriculare: "; std::cin >> nrInmatric;
                std::cout << "Marca: "; std::cin >> marca;
                std::cout << "Model: "; std::cin >> model;
                std::cout << "Kilometraj actual: "; std::cin >> kilometraj;
                std::cout << "Capacitate rezervor (Litri): "; std::cin >> capRez;
                std::cout << "Tip caroserie (ex: Sedan/SUV): "; std::cin >> caroserie;
                std::cout << "Numar locuri: "; std::cin >> locuri;
                std::cout << "Consum mediu (L/100km): "; std::cin >> consum;

                std::cout << "--- Data Expirare ITP ---" << std::endl;
                std::cout << "Anul (ex: 2026): "; std::cin >> anITP;
                std::cout << "Luna (1-12): "; std::cin >> lunaITP;
                std::cout << "Ziua (1-31): "; std::cin >> ziITP;

                std::cout << "--- Data Expirare RCA ---" << std::endl;
                std::cout << "Anul (ex: 2026): "; std::cin >> anRCA;
                std::cout << "Luna (1-12): "; std::cin >> lunaRCA;
                std::cout << "Ziua (1-31): "; std::cin >> ziRCA;

                std::chrono::sys_days dataITP = creeazaData(anITP, lunaITP, ziITP);
                std::chrono::sys_days dataRCA = creeazaData(anRCA, lunaRCA, ziRCA);

                // Apelăm constructorul complet cu toți cei 12 parametri ai clasei Car
                flota.push_back(std::make_unique<Car>(
                    tipCombustibil, serieSas, nrInmatric, marca, model,
                    kilometraj, capRez, caroserie, locuri, consum,
                    dataITP, dataRCA
                ));

                std::cout << "Masina adaugata cu succes!" << std::endl;
                break;
            }
            case 3: {
                int index;
                std::cout << "Introdu indexul masinii pe care vrei sa o stergi (0 - " << flota.size() - 1 << "): ";
                std::cin >> index;
                if (index >= 0 && index < static_cast<int>(flota.size())) {
                    flota.erase(flota.begin() + index);
                    std::cout << "Masina a fost stearsa din sistem!" << std::endl;
                } else {
                    std::cout << "Index invalid!" << std::endl;
                }
                break;
            }
            case 4: {
                int indexMasina, indexSofer;
                std::cout << "Index masina (0 - " << flota.size() - 1 << "): "; std::cin >> indexMasina;

                std::cout << "Soferi disponibili:" << std::endl;
                for (std::size_t i = 0; i < soferi.size(); i++) {
                    std::cout << i << ". " << soferi[i]->get_nume() << std::endl;
                }
                std::cout << "Alege sofer: "; std::cin >> indexSofer;

                if (indexMasina >= 0 && indexMasina < static_cast<int>(flota.size()) &&
                    indexSofer >= 0 && indexSofer < static_cast<int>(soferi.size())) {

                    if (!flota[indexMasina]->isActiv()) {
                        std::cout << "EROARE: Masina este inactiva (verifica actele) si nu poate primi sofer!" << std::endl;
                    } else {
                        bool success = flota[indexMasina]->asigneazaSofer(soferi[indexSofer].get());
                        if (success) std::cout << "Sofer asignat cu succes!" << std::endl;
                    }
                } else {
                    std::cout << "Date invalide!" << std::endl;
                }
                break;
            }
            case 5: {
                int indexMasina;
                std::cout << "Index masina: "; std::cin >> indexMasina;
                if (indexMasina >= 0 && indexMasina < static_cast<int>(flota.size())) {
                    flota[indexMasina]->elibereazaSofer();
                } else {
                    std::cout << "Index invalid!" << std::endl;
                }
                break;
            }
            case 6: {
                int indexMasina;
                double km;
                std::cout << "Index masina: "; std::cin >> indexMasina;
                std::cout << "Numar kilometri parcursi: "; std::cin >> km;
                if (indexMasina >= 0 && indexMasina < static_cast<int>(flota.size())) {
                    flota[indexMasina]->inregistreazaCursa(km);
                } else {
                    std::cout << "Index invalid!" << std::endl;
                }
                break;
            }
            case 7: {
                int indexMasina;
                double litri;
                std::cout << "Index masina: "; std::cin >> indexMasina;
                std::cout << "Litri de alimentat: "; std::cin >> litri;
                if (indexMasina >= 0 && indexMasina < static_cast<int>(flota.size())) {
                    flota[indexMasina]->alimenteaza(litri);
                } else {
                    std::cout << "Index invalid!" << std::endl;
                }
                break;
            }
            case 8: {
                std::cout << "\n--- DASHBOARD MENTENANTA (ACTE) ---" << std::endl;
                if (flota.empty()) {
                    std::cout << "Nu exista masini in flota." << std::endl;
                } else {
                    for (std::size_t i = 0; i < flota.size(); i++) {
                        std::cout << "Masina " << i << " [Stare generala: " << (flota[i]->isActiv() ? "ACTIV" : "INACTIV") << "]:" << std::endl;

                        int zileITP = flota[i]->zileITP();
                        if (zileITP < 0) std::cout << "  [CRITIC] ITP expirat de " << -zileITP << " zile!\n";
                        else if (zileITP <= 30) std::cout << "  [WARNING] ITP expira in " << zileITP << " zile.\n";
                        else std::cout << "  [OK] ITP valabil (" << zileITP << " zile ramase).\n";

                        int zileRCA = flota[i]->zileRCA();
                        if (zileRCA < 0) std::cout << "  [CRITIC] RCA expirat de " << -zileRCA << " zile!\n";
                        else if (zileRCA <= 30) std::cout << "  [WARNING] RCA expira in " << zileRCA << " zile.\n";
                        else std::cout << "  [OK] RCA valabil (" << zileRCA << " zile ramase).\n";
                    }
                }
                break;
            }
            case 9: {
                int indexMasina, tipAct;
                int an, luna, zi;

                std::cout << "Index masina: "; std::cin >> indexMasina;
                if (indexMasina >= 0 && indexMasina < static_cast<int>(flota.size())) {
                    std::cout << "Ce act reinnoiesti? (1 = ITP, 2 = RCA): "; std::cin >> tipAct;

                    std::cout << "Introdu noua data de expirare din actul eliberat:" << std::endl;
                    std::cout << "Anul (ex: 2027): "; std::cin >> an;
                    std::cout << "Luna (1-12): "; std::cin >> luna;
                    std::cout << "Ziua (1-31): "; std::cin >> zi;

                    std::chrono::sys_days dataNoua = creeazaData(an, luna, zi);

                    if (tipAct == 1) {
                        flota[indexMasina]->actualizeazaITP(dataNoua);
                    } else if (tipAct == 2) {
                        flota[indexMasina]->actualizeazaRCA(dataNoua);
                    } else {
                        std::cout << "Tip de act invalid!" << std::endl;
                    }

                    std::cout << "Stare actualizata masina: " << (flota[indexMasina]->isActiv() ? "ACTIV" : "INACTIV") << std::endl;
                } else {
                    std::cout << "Index invalid!" << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Se inchide sistemul Holver. La revedere!" << std::endl;
                ruleaza = false;
                break;
            default:
                std::cout << "Optiune invalida! Incearca din nou." << std::endl;
        }
    }

    return 0;
}