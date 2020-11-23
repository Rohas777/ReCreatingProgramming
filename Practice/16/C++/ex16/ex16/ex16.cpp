#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "ru");
	int n; std::cout << "Введите колличество билетов Суслика: " << std::endl;
	std::cin >> n;
	std::string tickets;
	std::string symbols = "";
	std::cout << "Введите номера билетов через пробел: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cin >> tickets;
		if ((tickets[0] == 'a') && (tickets[4] == '5') && (tickets[5] == '5') && (tickets[6] == '6') && (tickets[7] == '6') && (tickets[8] == '1')) {
			symbols = symbols + tickets + ' ';
		}
	}
	if (symbols == "") std::cout << -1;
	else std::cout << "Билеты Суслика:" << std::endl << symbols;
}