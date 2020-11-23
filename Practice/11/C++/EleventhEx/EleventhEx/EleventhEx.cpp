#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");
    int a, r, n;
    std::cout << "Введите в первой строке число возводимое в степень, во второй строке целое число - степень:" << std::endl;
    std::cin >> a >> n;
    r = a;
    for (int i = 1; i < n; i++) {
        r *= a;
    }
    std::cout << r;
}