#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, i;
    std::cout << "Введите первое число a: "; std::cin >> a;
    std::cout << "Введите второе число b: "; std::cin >> b;
    i = a; a = b; b = i;
    std::cout << "Обмен через третью переменну: a = " << a << ", b = " << b << std::endl;
    a = a + b; b = a - b; a = a - b;
    std::cout << "Обратный обмен без дополнительной переменной: a = " << a << ", b = " << b;

}