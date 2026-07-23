//
// Created by rzv on 7/23/26.
//

#ifndef FLOTAAUTO_TIMEUTILS_H
#define FLOTAAUTO_TIMEUTILS_H

#include "RoadVehicle.h"
#include <chrono>

std::chrono::sys_days current_day() ;
bool expired(std::chrono::sys_days random_date) ;
bool expires_in_chunk_time(std::chrono::sys_days date) ;//chunk time is DAYS_BEFORE_EXPIRATION  defined in RoadVehicle.h

#endif //FLOTAAUTO_TIMEUTILS_H