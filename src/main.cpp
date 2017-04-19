#include "hpp/roman.hpp"
#include <iostream>

int main() {
	Roman *a = new Roman("pene");

	std::cout << a->getLength() << std::endl;

	return 0;
}