#include <iostream>

int main() {
	setlocale(LC_ALL, "Rus");

	double a, b, c, D, x1, x2;
	std::cout << "Введите три вещественных числа a, b, c каждый в отдельной строке:" << std::endl;
	std::cin >> a >> b >> c;
	D = b * b - 4 * a * c;
	x1 = (-b + sqrt(D)) / (2 * a);
	x2 = (-b - sqrt(D)) / (2 * a);

	if (a == 0){
		if (b == 0) {
			std::cout << "Любой корень";
		} else {
			x1 = -c / b;
			std::cout << "x = " << x1;
		}
	}
	else if (b == 0) {
		x1 = sqrt(c / a);
		x2 = -x1;
		std::cout << "x1 = " << x1 << std::endl << "x2 = " << x2;
	} else {
		if (D < 0) {
			std::cout << "Решение не имеет корней";
		}
		else if (D == 0) {
			std::cout << "x = " << x1;
		}
		else if (D > 0) {
			std::cout << "x1 = " << x1 << std::endl << "x2 = " << x2;
		}
	}
}