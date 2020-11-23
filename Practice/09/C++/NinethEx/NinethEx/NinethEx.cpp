#include <iostream>

int main(){
    setlocale(LC_ALL, "Rus");
    int h1, h2, m1, m2, t1, t2;
    char c;
    std::cout << "Введите время прибытия первого человека : " << std::endl;
    std::cin >> h1 >> c >> m1;
    std::cout << "Введите время прибытия второго человека : " << std::endl;
    std::cin >> h2 >> c >> m2;
    t1 = m1 + h1 * 60;
    t2 = m2 + h2 * 60;
    
    if (h1 > 23 || h2 > 23 || h1 < 0 || h2 < 0 || m1 > 59 || m2 > 59 || m1 < 0 || m2 < 0 || c != ':') {
        std::cout << "Вы неверно ввели формат времени";
    }
    else if (t2 - t1 > 15 || t1 - t2 > 15) {
        std::cout << "Встреча не состоится";
    }
    else {
        std::cout << "Встреча состоится";
    }
}