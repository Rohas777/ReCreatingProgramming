#include <iostream>

struct IntArray {
    int* data;
    int size;
};

/** Создаёт динамический массив размера size и сохраняет его в поле data переменной arr. 
Поле size структуры arr становится равным параметру size */
void create(IntArray* arr, int size) {
    arr->data = new int[size];
    arr->size = size;
}
void create(IntArray& arr, int size) {
    arr.data = new int[size];
    arr.size = size;
}
/** Возвращает элемент массива с индексом index, при этом проверяет выход за границы массива. 
Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
int get(IntArray* arr, int index) {
    if (index < 0 or index >= arr->size) return 0;
    return arr->data[index];
}
int get(IntArray& arr, int index) {
    if (index < 0 or index >= arr.size) return 0;
    return arr.data[index];
}
/** Изменяет значение элемента массива с индексом index на значение параметра value, 
при этом проверяет выход за границы массива. Если index лежит за пределами массива, 
вывести сообщение об ошибке и прервать работу программы */
void set(IntArray* arr, int index, int value) {
    if (index < 0 or index >= arr->size) {
        std::cout << "Ошибка! Недопустимый индекс!!!";
        return;
    }
    arr->data[index] = value;
}
void set(IntArray& arr, int index, int value) {
    if (index < 0 or index >= arr.size) {
        std::cout << "Ошибка! Недопустимый индекс!!!";
        return;
    }
    arr.data[index] = value;
}
/** Выводит на экран содержимое массива в формате: [1, 2, 3] */
void print(IntArray* arr) {
    std::cout << "[";
    for (int i = 0; i < arr->size - 1; i++) {
        std::cout << arr->data[i] << ",";
    }
    std::cout << arr->data[arr->size - 1] << "]" << std::endl;
}
void print(IntArray& arr) {
    std::cout << "[";
    for (int i = 0; i < arr.size - 1; i++) {
        std::cout << arr.data[i] << ",";
    }
    std::cout << arr.data[arr.size - 1] << "]" << std::endl;
}
/** Изменяет размер массива с сохранением элементов. Если новый размер меньше, хвостовые элементы обрезаются, 
если больше, то дополнительные элементы инициализируются нулём */
void resize(IntArray* arr, int newSize) {
    int* tempArr = new int[newSize];
    if (newSize < arr->size) {
        for (int i = 0; i < newSize; i++) {
            tempArr[i] = arr->data[i];
        }
    }
    else if (newSize >= arr->size) {
        for (int i = 0; i < arr->size; i++) {
            tempArr[i] = arr->data[i];
        }
        for (int i = arr->size; i < newSize; i++) {
            tempArr[i] = 0;
        }
    }
    delete arr->data;
    arr->data = tempArr;
    arr->size = newSize;
}
void resize(IntArray& arr, int newSize) {
    int* tempArr = new int[newSize];
    if (newSize < arr.size) {
        for (int i = 0; i < newSize; i++) {
            tempArr[i] = arr.data[i];
        }
    }
    else if (newSize >= arr.size) {
        for (int i = 0; i < arr.size; i++) {
            tempArr[i] = arr.data[i];
        }
        for (int i = arr.size; i < newSize; i++) {
            tempArr[i] = 0;
        }
    }
    delete arr.data;
    arr.data = tempArr;
    arr.size = newSize;
}
/** Освобождает память занятую массивом. Поле data становится равным nullptr, 
поле size становится равным нулю. Предусмотреть случай попытки удаления уже удалённого массива */
void destroy(IntArray& arr) {
    if (arr.data != nullptr) {
        delete arr.data;
        arr.data = nullptr;
        arr.size = 0;
    }
}
void destroy(IntArray* arr) {
    if (arr->data != nullptr) {
        delete arr->data;
        arr->data = nullptr;
        arr->size = 0;
    }
}


int main()
{
    IntArray array;
    create(array, 30);
    for (int i = 0; i < array.size; i++) set(array, i, i + 1);
    print(array);
    resize(array, 50);
    print(array);
    resize(array, 10);
    print(array);
    destroy(array);
}
