//
// Created by rzv on 8/19/26.
//

#ifndef FLOTAAUTO_EXCEPTIONS_H
#define FLOTAAUTO_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class DriverLicenseException : public std::runtime_error {
public:
    explicit DriverLicenseException(const std::string& mesaj) : std::runtime_error(mesaj){}
};

// Pentru situația când vehiculul este inactiv (ex: în service sau casat)
class InactiveVehicleException : public std::runtime_error {
public:
    explicit InactiveVehicleException(const std::string& message)
        : std::runtime_error(message) {}
};

// Pentru situația când mașina are deja un șofer la volan
class VehicleOccupiedException : public std::runtime_error {
public:
    explicit VehicleOccupiedException(const std::string& message)
        : std::runtime_error(message) {}
};


class FuelCapacityException : public std::runtime_error {
public:
    explicit FuelCapacityException(const std::string& message) : std::runtime_error(message){}
};


class VanWeightException : public std::runtime_error {
public:
    explicit VanWeightException(const std::string& message) : std::runtime_error(message){}
};

#endif //FLOTAAUTO_EXCEPTIONS_H