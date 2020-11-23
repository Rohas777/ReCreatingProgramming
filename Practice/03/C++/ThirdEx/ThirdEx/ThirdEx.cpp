#include <iostream>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
    cout << "===Блок INT===" << endl;
    int a, b;
    cout << "Первое число: "; cin >> a;
    cout << "Второе число: "; cin >> b;
    cout << "Сложение: " << a + b << endl;
    cout << "Вычитание: " << a - b << endl;
    cout << "Умножение: " << a * b << endl;
    cout << "Деление: " << a / b << endl;

    cout << "===Блок DOUBLE===" << endl;
    double e, f;
    cout << "Первое число: "; cin >> e;
    cout << "Второе число: "; cin >> f;
    cout << "Сложение: " << e + f << endl;
    cout << "Вычитание: " << e - f << endl;
    cout << "Умножение: " << e * f << endl;
    cout << "Деление: " << e / f << endl;

    cout << "===Блок INT/DOUBLE===" << endl;
    int g; double h;
    cout << "Первое число: "; cin >> g;
    cout << "Второе число: "; cin >> h;
    cout << "Сложение: " << g + h << endl;
    cout << "Вычитание: " << g - h << endl;
    cout << "Умножение: " << g * h << endl;
    cout << "Деление: " << g / h << endl;

    cout << "===Блок DOUBLE/INT===" << endl;
    double i; int j;
    cout << "Первое число: "; cin >> i;
    cout << "Второе число: "; cin >> j;
    cout << "Сложение: " << i + j << endl;
    cout << "Вычитание: " << i - j << endl;
    cout << "Умножение: " << i * j << endl;
    cout << "Деление: " << i / j << endl;
}
