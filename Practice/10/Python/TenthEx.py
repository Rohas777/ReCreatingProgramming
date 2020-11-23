print ("Введите значения s, l1, r1, l2, r2 через пробел, каждый диапозон начинается с l и заканчивается на r:")
s, l1, r1, l2, r2 = map(int, input().split(sep =' '))

if (r1 <= l1) or (r2 <= l2):
    print ("Вы ввели неверные значения, в диапозоне первое число всегда должно быть меньше последнего")
elif (s <= r1 + r2) and (s >= l1 + l2):
    if l1 + r2 == s:
        print(l1, r2)
    elif l1 + r2 > s:
        print(l1, r2 - (l1 + r2 - s))
    elif l1 + r2 < s:
        print(l1 - (l1 + r2 - s), r2)
else: print('-1')