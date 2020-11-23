#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    std::cout << "Введите число для проверки: ";
    std::cin >> n;
    if (n < 1) {
        std::cout << "Вы ввели некорректное число";
        return 0;
    }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                std::cout << "Составное";
                return 0;
            }
        }
     std::cout << "Простое";
}