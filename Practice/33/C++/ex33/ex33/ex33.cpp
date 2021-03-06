﻿#include <iostream>

int *create(int size, int first = 0, int step = 0) {
    int* arr = new int[size];
    *arr = first;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + step;
    }
    return arr;
}

int* sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            std::swap(arr[j - 1], arr[j]);
        }
    }
    return arr;
}

void print(int* arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size - 1; i++) {
        std::cout << arr[i] << ",";
    }
    std::cout << arr[size - 1] << "]";
}

int main() {
    setlocale(LC_ALL, "");
    int step, lenght, first;
    std::cout << "Введите длину массива: "; std::cin >> lenght;
    std::cout << "Введите первый элемент: "; std::cin >> first;
    std::cout << "Введите шаг арифметической прогрессии: "; std::cin >> step;
    int *arr = create(lenght, first, step);
    sort(arr, lenght);
    print(arr, lenght);
}