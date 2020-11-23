#include <iostream>

int main(){
    setlocale(LC_ALL, "Rus");
    long long int s, l1, l2, r1, r2;
    std::cout << "Введите значения s, l1, l2, r1, r2 через пробел, каждый диапозон начинается с l и заканчивается на r:" << std::endl;
    std::cin >> s >> l1 >> r1 >> l2 >> r2;

    if ((r1 <= l1) || (r2 <= l2)) { std::cout << "Вы ввели неверные значения, в диапозоне первое число всегда должно быть меньше последнего"; }
    else if ((s <= r1 + r2) && (s >= l1 + l2)) {
        if (l1 + r2 == s) {
            std::cout << l1 << ' ' << r2;
        } else  if (l1 + r2 > s) {
            std::cout << l1 << ' ' << r2 - (l1 + r2 - s);
        } else  if (l1 + r2 < s) {
            std::cout << l1 - (l1 + r2 - s) << ' ' << r2;
        } 
    } else {
        std::cout << -1;
    }
} 