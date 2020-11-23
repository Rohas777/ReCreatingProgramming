#include <iostream>
#include "factorial.h"

double C(int n, int k) {
	return fact(n) / (fact(k) * fact(n - k));
}