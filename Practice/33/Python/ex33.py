import builtins

def create(lenght, first = 0, step = 0):
    arr = []
    arr.insert(0, first)
    for i in range(1, lenght):
        arr.append(arr[i-1] + step)
    return arr

def sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >=0 and key < arr[j] :
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr

def print(arr):
    builtins.print(arr)

lenght = input('Введите длину массива: ')
first = input('Введите первый элемент: ')
step = input('Введите шаг арифметической прогрессии: ')
print(sort(create(int(lenght), int(first), int(step))))