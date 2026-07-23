#include <iostream>
#include  <vector>
#include <string>
#include <memory>
#include "Driver.h"
#include "Car.h"
#include <chrono>

int main() {
    std::vector<std::string> p = {"B"};
    std::unique_ptr<Driver> sofer1 = std::make_unique<Driver>("Singiorzan Sorin", "0000000000001", p);

    std::unique_ptr<Car> masina1 = std::make_unique<Car>(
        "Benzina",
        "VIN123456789",
        "TM07RZN",
        "BMW",
        "X3",
        360255,
        60.0,
        "SUV",
        5,
        11.0,
        std::chrono::year(2027) / std::chrono::May / 20,
        std::chrono::year(2027) / std::chrono::April / 15
        );
    masina1->asigneazaSofer(sofer1.get());
    std::cout << "Masina a fost alocata cu succes soferului pe Heap folosind Modern C++!" << std::endl;

    std::cout << masina1->get_sofer()->get_nume() << std::endl;
    return 0;
}