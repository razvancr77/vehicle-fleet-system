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

    return 0;
}