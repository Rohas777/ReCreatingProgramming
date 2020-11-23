#include <iostream>
#include <ctime>

int main() {
	setlocale(LC_ALL, "ru");
	int u = 1;
	std::cout << "Здравствуйте! Вас приветствует игра \"Угадай число\". Компьютер загадает случайное число от 0 до 100.\nВаша задача угадать это число. На всё про всё вам даётся 5 попыток. Желаем вам удачи!" << std::endl;
	while(u) {
		std::cout << "Поехали!" << std::endl;
		srand(time(0));
		int userChange; int maxUserTry = 5;
		int n = 0 + rand() % 100 + 1;
		for (int userTry = 1; userTry <= maxUserTry; userTry++) {
			std::cin >> userChange;
			if (userChange == n) {
				std::cout << "Поздравляю! Вы угадали" << std::endl;
				break;
			}
			else if (userTry == maxUserTry) {
				std::cout << "Вы проиграли. Было загадано: " << n << std::endl;
				break;
			}
			else if (userChange < n) std::cout << "Загаданное число больше" << std::endl;
			else if (userChange > n) std::cout << "Загаданное число меньше" << std::endl;
		}
		std::cout << "Хотите начать сначала? (1 - ДА )" << std::endl;
		std::cin >> userChange;
		if (userChange == 1) u = 1;
		else u = 0;
	}	
}