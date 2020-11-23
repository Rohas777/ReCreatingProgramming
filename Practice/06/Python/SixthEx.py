import math

print ("Введите три вещественных числа a, b, c каждый в отдельной строке:")
a = float(input())
b = float(input())
c = float(input())
D = b * b - 4 * a * c

if a == 0:
    if b == 0:
        print("Любой корень")
    else:
        x1 = -c / b
        print("x = " + str(x1))
elif b == 0:
    x1 = math.sqrt(c / a)
    x2 = -x1
    print("x1 = " + str(x1))
    print("x2 = " + str(x2))
else:
    if D < 0:
        print("Решение не имеет корней")
    elif D == 0:
        x1 = (-b + math.sqrt(D)) / (2 * a)
        print("x = " + str(x1))
    elif D > 0:
        x1 = (-b + math.sqrt(D)) / (2 * a)
        x2 = (-b - math.sqrt(D)) / (2 * a)
        print("x1 = " + str(x1))
        print("x2 = " + str(x2))