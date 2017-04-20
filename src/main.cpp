#include "hpp/roman.hpp"
#include <iostream>

/**
 * text
 */
int main() {
	Roman *a = new Roman("X");

	std::cout << a->getNumber() << std::endl;

	return 0;
}