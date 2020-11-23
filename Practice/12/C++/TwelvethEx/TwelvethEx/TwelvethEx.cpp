#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, r;
    r = 1;
    std::cout << "Введите число, факториал которого хотите узнать: ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        r *= i;
    }
    std::cout << r;
}