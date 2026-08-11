//
// Created by rzv on 7/23/26.
//

#ifndef FLOTAAUTO_TIMEUTILS_H
#define FLOTAAUTO_TIMEUTILS_H

#include "RoadVehicle.h"
#include <chrono>

std::chrono::sys_days current_day() ;
bool expired(std::chrono::sys_days random_date) ;
int days_until_expiration(std::chrono::sys_days date) ;//DAYS_BEFORE_EXPIRATION  defined in RoadVehicle.h

#endif //FLOTAAUTO_TIMEUTILS_H