maximum, Max, n = 0, -1, 1
black = red = 0
amount = [0] * 37
while n > 0:
    n = int(input())
    if n > 36:
        print("Число должно быть не больше 36", end = '')
        break;
    amount[n] += 1;
    if (n == 1 or n == 3 or n == 5 or n == 7 or n == 9 or n == 12 or n == 14 or n == 16 or n == 18 or n == 19 or n == 21 or n == 23 or n == 25 or n == 27 or n == 30 or n == 32 or n == 34 or n == 36):
        red += 1
    elif (n != 0):
        black += 1
    i = 0
    while i <= 36:
        if amount[i] > maximum:
            maximum = amount[i]
        i += 1
    i = 0
    while i <= 36:
        Max += 1
        if amount[i] == maximum:
            print(str(Max), end = ' ')
        i += 1
    Max = -1
    i = 0
    print('')
    while i <= 36:
        if n == i:
            print('', end = '')
        else:
            print(str(i), end = ' ')
        i += 1
    print('\n' + str(red) + ' ' + str(black) + '\n')