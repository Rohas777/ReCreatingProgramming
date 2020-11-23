#include <iostream>

int maximum = 0, Max = -1, n = 1, black = 0, red = 0, amount[37];

int main() {
    setlocale(LC_ALL, "ru");
    while (n > 0) {
        std::cin >> n;
        if (n > 36) {
            std::cout << "Число должно быть не больше 36";
            return 0;
        }
        amount[n] += 1;
        if (n == 1 || n == 3 || n == 5 || n == 7 || n == 9 || n == 12 || n == 14 || n == 16 || n == 18 || n == 19 || n == 21 || n == 23 || n == 25 || n == 27 || n == 30 || n == 32 || n == 34 || n == 36) {
            red++;
        } else if (n != 0) {
           black++; 
        } 
        for (int i = 0; i <= 36; i++)
        {
            if (amount[i] > maximum) {
                maximum = amount[i];
            }
        }
        for (int i = 0; i <= 36; i++)
        {
            Max++;
            if (amount[i] == maximum) {
                std::cout << Max << ' ';
            }
        }
        Max = -1;
        std::cout << '\n';
        for (int i = 0; i <= 36; i++) {
            if (n == i) {
                std::cout << "";
            }
            else {
                std::cout << i << ' ';
            }
        }
        std::cout << std::endl << red << ' ' << black << std::endl;
        std::cout << '\n';
    }
}