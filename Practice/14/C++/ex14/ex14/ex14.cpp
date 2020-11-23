#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    int n, s;
    s = 0;
    std::cout << "Введите число: ";
    std::cin >> n;
    if (n < 0) {
        std::cout << "Вы не верно ввели число";
        return 0;
    }
    for (int x = 1; x <= n; x++) {
        if ((x & (x-1)) == 0) {
            s += 1;
        }
    }
    std::cout << s;
}