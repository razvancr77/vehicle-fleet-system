//
// Created by rzv on 7/23/26.
//

#include "TimeUtils.h"
#include <iostream>

std::chrono::sys_days current_day() {
    std::chrono::sys_days azi = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
    return azi;
}

bool expired(std::chrono::sys_days random_date) {
    std::chrono::sys_days azi = current_day();
    return azi > random_date;
}

int days_until_expiration(std::chrono::sys_days date) {
    std::chrono::sys_days azi = current_day();
    std::chrono::days durata = date - azi;
    return durata.count();
}

