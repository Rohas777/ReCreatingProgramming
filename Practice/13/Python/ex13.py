import math

print ("Введите число для проверки:", end = ' ')
n = int(input())
i = 2
r = 0
while i <= math.sqrt(n):
    if n % i == 0:
        print("Составное")
        r = 1
        break
    i += 1
if r != 1:
    print("Простое")