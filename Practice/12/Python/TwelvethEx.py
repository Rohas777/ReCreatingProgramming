print("Введите число, факториал которого хотите узнать: ", end = ' ')
n = int(input())
r = i = 1
while i <= n:
    r *= i
    i += 1
print(r)