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

bool expires_in_chunk_time(std::chrono::sys_days date) {
    std::chrono::sys_days azi = current_day();
    if (!expired(date)) {//deci azi e < data
        return (date - azi) <= std::chrono::days(DAYS_BEFORE_EXPIRATION);//transf numarul in numar de zile
    }
    else {
        std::cout << "E deja expirat" << std::endl;
        return true;
    }
}

