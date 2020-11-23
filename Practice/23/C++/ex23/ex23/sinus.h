#include "factorial.h"
#include <iostream>
#include <cmath>

double sin(double x, double k) {
	double result = 0;
	for (double n = 0; n < k; n++) {
		result += pow(-1, n) * (pow(x, 2 * n + 1) / (fact(2 * n + 1)));
	}
	return result;
}