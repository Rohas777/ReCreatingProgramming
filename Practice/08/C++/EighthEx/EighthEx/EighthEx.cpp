#include <iostream>

int main() {
	setlocale(LC_ALL, "Rus");
	double a, b, r;
	char c;
	std::cout << "Введите пример для расчёта:" << std::endl;
	std::cin >> a >> c >> b;
	if (c == '+') { r = a + b; }
	else if (c == '-') { r = a - b; }
	else if (c == '*') { r = a * b; }
	else if (c == '/') { r = a / b; }
	else { std::cout << "Вы ввели неизвестное действие"; }
	std::cout << a << ' ' << c << ' ' << b << ' ' << '=' << ' ' << r;
}