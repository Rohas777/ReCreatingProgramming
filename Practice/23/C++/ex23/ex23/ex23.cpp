#include <iostream>
#include <iomanip> 
#include "factorial.h"
#include "sinus.h"
#include "combination.h"

const double PI = 3.141592653589793;
int main(){
	std::cout << 'n' << '\t' << "n!" << std::endl;
	for (int n = 1; n <= 10; n++) {
		std::cout << n << '\t' << fact(n) << std::endl;
	}
	std::cout << std::endl;
	std::cout << 'x' << '\t' << "sin(x)" << std::endl;
	for (double x = 0; x <= PI / 4; x += PI / 180) {
		std::cout << std::setprecision(4) << x << '\t' << sin(x, 5) << std::endl;
	}
	std::cout << std::endl;
	std::cout << 'k' << '\t' << "C(k, 10)" << std::endl;
	for (int n = 0; n <= 10; n++) {
		std::cout << n << '\t' << C(10, n) << std::endl;
	}
}