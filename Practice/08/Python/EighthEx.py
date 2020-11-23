print ("Введите пример для расчёта:")

a, c, b = input().split()
a = float(a)
b = float(b)
c = str(c)

if c == "+": print(a, "+", b, "=", a + b)
elif c == "-": print(a, "-", b, "=", a - b)
elif c == "*": print(a, "*", b, "=", a * b)
elif c == "/": print(a, "/", b, "=", a / b)
else: print("Вы ввели неизвестное действие")