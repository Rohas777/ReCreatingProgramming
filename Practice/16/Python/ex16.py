print("Введите колличество билетов Суслика: ")
n = int(input())
symbols = ""
print("Введите номера билетов каждый в новой строке: ")
i = 0
while i < n:
    tickets = input()
    if (tickets[0] == 'a') and (tickets[4] == '5') and (tickets[5] == '5') and (tickets[6] == '6') and (tickets[7] == '6') and (tickets[8] == '1'):
        symbols += tickets + " "
    i += 1
if symbols == "": print(-1)
else: print("Билеты Суслика:\n" + symbols)