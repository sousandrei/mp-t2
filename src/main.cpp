#include "hpp/roman.hpp"
#include <iostream>

int main() {
	Roman *a = new Roman("X");

	std::cout << a->getNumber() << std::endl;

	return 0;
}