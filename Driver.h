#include <string>
#include <vector>

#ifndef FLOTAAUTO_DRIVER_H
#define FLOTAAUTO_DRIVER_H

class Driver {
    private:
    std::string nume;
    std::string cnp;
    std::vector<std::string> permis;

    public:
    Driver(const std::string& n, const std::string& c, const std::vector <std::string>& p);
    ~Driver();
    //getterii
    std::string get_nume() const;
    std::string get_cnp() const;
    std::vector<std::string> get_permis() const;
};

#endif //FLOTAAUTO_DRIVER_H