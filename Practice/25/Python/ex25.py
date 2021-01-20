from random import randint
from  math import sqrt

def sort_order(arr, check = True):
    if check:
        for i in range (len(arr) - 1):
            if arr[i] > arr[i + 1]:
                return False
        return True
    else:
        for i in range (len(arr) - 1):
            if arr[i] < arr[i + 1]:
                return False
        return True

def BozoSort(arr, check):
   result = None
   if (type(arr[0]) == list):
      line = []
      rows = len(arr)
      cols = rows
      for i in range(rows):
         for j in range(cols):
            line += [ arr[i][j] ]
      result = sort_order(line, check)
   else:
      result = sort_order(arr, check)
   
   print(result)
def BozoSort(a, b, c, check):
   print(*sort_order([a,b,c], check))


arr_len = int(input('Введите длинну одномерного массива: '))
arr_len_sqrt = int(sqrt(arr_len))
arr = list(map(int, input('Введите массив через пробел: ').split(' ')))

line = arr

int1 = arr[0]
int2 = arr[1]
int3 = arr[2]

sqr = []
for i in range(arr_len_sqrt):
   sqr += [[]]
   for j in range(arr_len_sqrt):
      sqr[i] += [ line[i * arr_len_sqrt + j] ]
   
BozoSort(line, True)
BozoSort(line, False)

BozoSort(sqr, True)
BozoSort(sqr, False)

BozoSort(int1, int2, int3, True)
BozoSort(int1, int2, int3, False)