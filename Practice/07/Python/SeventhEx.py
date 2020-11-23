import math

print ("Выберите способ рассчёта площади треугольника:\n1 - ввод параметров треугольника через длины сторон\n2 - ввод параметров через координаты вершин")
user_change = float(input())
if user_change == 1:
    print("Введите длины сторон каждую в новой строке:")
    a = float(input())
    b = float(input())
    c = float(input())
    p = (a + b + c) / 2
    S = math.sqrt(p * (p - a) * (p - c) * (p - b))
    print ("S = ", str(S), sep = "")
elif user_change == 2:
    print ("Введите координаты каждую пару в новой строке:")
    A1, A2 = map(float, input().split())
    B1, B2 = map(float, input().split())
    C1, C2 = map(float, input().split())
    S = abs((B1 - A1) * (C2 - A1) - (C1 - A1) * (B2 - A2)) / 2
    print ("S = ", str(S), sep = "")
else:
    print("Вы неверно указали метод рассчёта")