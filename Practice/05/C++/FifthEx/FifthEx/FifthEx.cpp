#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    double x, x0, V0, t, g, a, S;
    g = 9.8;
    std::cout << "Введите параметры через пробел:" << std::endl;
    std::cin >> x0 >> V0 >> t;
    a = g;
    x = x0 + V0 * t - g * t * t / 2;
    S = x - x0;
    std::cout << "S = " << S;
}