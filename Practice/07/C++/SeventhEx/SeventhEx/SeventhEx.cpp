#include <iostream>
#include <math.h>

int main(){
    setlocale(LC_ALL, "Rus");
    std::cout << "Выберите способ рассчёта площади треугольника:\n1 - ввод параметров треугольника через длины сторон\n2 - ввод параметров через координаты вершин" << std::endl;
    int userChange;
    double A1, A2, B1, B2, C1, C2;
    double a, b, c, p, S;
    std::cin >> userChange;
    if (userChange == 1) {
        std::cout << "Введите длины сторон каждую в новой строке:" << std::endl;
        std::cin >> a >> b >> c;
        p = (a + b + c) / 2;
        S = sqrt(p * (p - a) * (p - c) * (p - b));
        std::cout << "S = " << S;
    }
    else if (userChange == 2) {
        std::cout << "Введите координаты каждую пару в новой строке:" << std::endl;
        std::cin >> A1; std::cin.ignore(1); std::cin >> A2;
        std::cin >> B1; std::cin.ignore(1); std::cin >> B2;
        std::cin >> C1; std::cin.ignore(1); std::cin >> C2;
        S = abs((B1 - A1) * (C2 - A1) - (C1 - A1) * (B2 - A2)) / 2;
        std::cout << "S = " << S;
    }
    else {
        std::cout << "Вы неверно указали метод рассчёта";
    }
}