#include "../hpp/roman.hpp"
#include <iostream>
#include <string>

Roman::Roman(std::string strNumber) { this->number = strNumber; }

int Roman::getLength() { return number.length(); }