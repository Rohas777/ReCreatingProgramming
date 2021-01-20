#include <iostream>
#include <random>
#include <vector>
#include <cmath>

int random(int size) {
	int res;
	res = std::rand() % size;
	return res;
}

void print(std::vector<int> arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		std:: cout << arr[i] << " ";
	}
	std::cout << "\n";
}

bool sortOrder(std::vector<int> arr, bool check = true) {
    if (check == true) {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
    }
    else {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

std::vector<int> BozoSort(std::vector<int> arr, bool check = true) {
    while (sortOrder(arr, check) == false) {
        for (int i = 0; i < arr.size(); i++) {
            int m = random(arr.size());
            int n = random(arr.size());
            std::swap(arr[m], arr[n]);
        }
    }
    return arr;
}

std::vector<int> BozoSort(std::vector<std::vector<int>> arr, bool check = true) {
    std::vector<int> res;
    for (int i = 0; i < arr.size(); i++) { 
        for (int j = 0; j < arr.size(); j++) { 
            res.push_back(arr[i][j]);
        }            
    }
    return BozoSort(res, check);
}

std::vector<int> BozoSort(int a, int b, int c, bool check = true) {
    std::vector<int> arr{ a, b, c };
    return BozoSort(arr, check);
}

int main(){
    int amount;
    std::cin >> amount;
    std::vector<int> i;
    std::vector<int> j;
    std::vector<std::vector<int>> matrix;
    for (int n = 1; n < amount + 1; n++)
    {
        int number;
        std::cin >> number;
        i.push_back(number);
        j.push_back(number);
        if (n % int(sqrt(amount)) == 0) {
            matrix.push_back(i);
            i.clear();
        }
    }
    std::cout << std::endl;
    print(BozoSort(j));
    print(BozoSort(j, false));
    print(BozoSort(matrix));
    print(BozoSort(matrix, false));
    print(BozoSort(j[0], j[1], j[2]));
    print(BozoSort(j[0], j[1], j[2], false));
}