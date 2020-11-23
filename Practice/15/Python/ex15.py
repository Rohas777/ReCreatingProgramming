import random

u = 1
print ("Здравствуйте! Вас приветствует игра \"Угадай число\". Компьютер загадает случайное число от 0 до 100.\nВаша задача угадать это число. На всё про всё вам даётся 5 попыток. Желаем вам удачи!")
while u:
    print("Поехали!")
    max_user_try = 5
    user_try = 1
    n = random.randint(0, 100)
    while user_try <= max_user_try:
        user_change = int(input())
        if user_change == n:
            print ("Поздравляю! Вы угадали")
            break
        elif user_try == max_user_try:
            print ("Вы проиграли. Было загадано:", n, sep = ' ')
            break
        elif user_change < n: print("Загаданное число больше")
        elif user_change > n: print("Загаданное число меньше")
        user_try += 1
    print("Хотите начать сначала? (1 - ДА )")
    user_change = input()
    if user_change == "1": u = 1
    else: u = 0