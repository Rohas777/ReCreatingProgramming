print ("Введите число: ", end = ' ')
n = int(input())
s = 0
x = 1
if n < 0:
    print ("Вы не верно ввели число")
else:
    while x <= n:
        if (x & (x-1)) == 0:
            s += 1
        x += 1
    print (s)