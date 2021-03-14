#include <iostream>

void create(int** arr, int size, int first = 0, int step = 0) {
	int *ptrArr = new int[size];
	*ptrArr = first;
	for (int i = 1; i < size; i++) {
		*(ptrArr + i) = *(ptrArr + i - 1) + step;
	}
    *arr = ptrArr;
}

int *sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            std::swap(arr[j - 1], arr[j]);
        }
    }
    return arr;
}

void print(int *arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size - 1; i++) {
        std::cout << arr[i] << ",";
    }
    std::cout << arr[size - 1] << "]";
}

void destroy(int** arr) {
    if (*arr != nullptr) {
        delete[] * arr;
        *arr = nullptr;
    }
}

int main(){
    setlocale(LC_ALL, "");
	int* arr;
    int step, lenght, first;
    std::cout << "Введите длину массива: "; std::cin >> lenght;
    std::cout << "Введите первый элемент: "; std::cin >> first;
    std::cout << "Введите шаг арифметической прогрессии: "; std::cin >> step;
    create(&arr, lenght, first, step);
    sort(arr, lenght);
    print(arr, lenght);
    destroy(&arr);
}