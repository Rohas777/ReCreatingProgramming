#include <iostream>

double BMI(double weight, double height) {
    return weight / pow(height / 100, 2);
}
void printBMI(double BMI) {
    if (BMI < 18.5) std::cout << "Underweight" << std::endl;
    else if (BMI < 25.0) std::cout << "Normal" << std::endl;
    else if (BMI < 30.0) std::cout << "Overweight" << std::endl;
    else std::cout << "Obesity" << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "Вас приветствует программа вычисления индекса массы тела\n" << std::endl;
    double weight, height;
    std::cout << "Введите вес в килограммах: ";
    std::cin >> weight;
    std::cout << "Введите рост в сантиметрах: ";
    std::cin >> height;
    printBMI(BMI(weight, height));
}