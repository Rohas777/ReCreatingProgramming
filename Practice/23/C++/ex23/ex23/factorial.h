#pragma once
#include <iostream>

double fact(double x) {
    if (x <= 0) return 1;
    else return x * fact(x - 1);
}