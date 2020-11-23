# 5. Падение объекта
import sys

g = 9.8
print ("Введите параметры через пробел:")
x0, V0, t = map(float, input().split())
a = g

x = x0 + V0 * t - (a * t * t) / 2
s = x - x0

print("S =", s)