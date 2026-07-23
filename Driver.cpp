//
// Created by rzv on 7/10/26.
//

#include "Driver.h"

//constructor
Driver::Driver(const std::string& n, const std::string& c,const std::vector<std::string>& p) : nume(n), cnp(c), permis(p) {
    // ceva
}

//destructor
Driver::~Driver() {
    //momentan nimic
}

//getterii
std::string Driver::get_nume() const {return this->nume;}
std::string Driver::get_cnp() const {return this->cnp;}
std::vector<std::string> Driver::get_permis() const  {return this->permis;}

