cmake_minimum_required(VERSION 4.0)
project(FlotaAuto)

set(CMAKE_CXX_STANDARD 20)

add_executable(FlotaAuto main.cpp
        Vehicle.cpp
        Vehicle.h
        Driver.cpp
        Driver.h
        Car.cpp
        Car.h
        RoadVehicle.cpp
        RoadVehicle.h
        TimeUtils.cpp
        TimeUtils.h
        Van.cpp
        Van.h
        Exceptions.h)
