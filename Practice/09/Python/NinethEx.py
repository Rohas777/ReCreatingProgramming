print ("Введите время прибытия первого человека:")
h1, m1 = map(int, input().split(sep = ":"))
print ("Введите время прибытия второго человека:")
h2, m2 = map(int, input().split(sep = ":"))
t = abs((m1 + h1 * 60) - (m2 + h2 *60))

if h1 > 23 or h1 < 0 or h2 > 23 or h2 < 0 or m1 > 59 or m2 > 59 or m1 < 0 or m2 < 0:
    print("Неверно указан формат времени")
elif t > 15:
    print("Встреча не состоится")
else:
    print("Встреча состоится")   