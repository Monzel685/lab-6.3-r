#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

// Рекурсивна функція для створення масиву
void create(int* arr, int size, int min, int max, int i = 0) {
    if (i < size) {
        arr[i] = min + rand() % (max - min + 1);
        create(arr, size, min, max, i + 1);
    }
}

// Рекурсивна функція для виведення масиву
void print(int* arr, const int size, int i = 0) {
    cout << setw(4) << arr[i];
    if (i < size - 1) {
        print(arr, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// Рекурсивна функція для підрахунку кількості додатних елементів
int countPositive(int* arr, const int size, int i = 0) {
    if (i == size)
        return 0;

    int count = arr[i] > 0 ? 1 : 0;
    return count + countPositive(arr, size, i + 1);
}

// Рекурсивна функція для сортування масиву за неспаданням
void sortAscending(int* arr, const int size, int i = 0, int j = 0) {
    if (i < size - 1) {
        if (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            sortAscending(arr, size, i, j + 1);
        }
        else {
            sortAscending(arr, size, i + 1, 0);
        }
    }
}

// Шаблонна рекурсивна функція для створення масиву
template <typename T>
void templateCreate(T* arr, int size, T min, T max, int i = 0) {
    if (i < size) {
        arr[i] = min + rand() % (max - min + 1);
        templateCreate(arr, size, min, max, i + 1);
    }
}

// Шаблонна рекурсивна функція для виведення масиву
template <typename T>
void templatePrint(T* arr, const int size, int i = 0) {
    cout << setw(4) << arr[i];
    if (i < size - 1) {
        templatePrint(arr, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// Шаблонна рекурсивна функція для підрахунку кількості додатних елементів
template <typename T>
int templateCountPositive(T* arr, const int size, int i = 0) {
    if (i == size)
        return 0;

    int count = arr[i] > 0 ? 1 : 0;
    return count + templateCountPositive(arr, size, i + 1);
}

// Шаблонна рекурсивна функція для сортування масиву за неспаданням
template <typename T>
void templateSortAscending(T* arr, const int size, int i = 0, int j = 0) {
    if (i < size - 1) {
        if (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            templateSortAscending(arr, size, i, j + 1);
        }
        else {
            templateSortAscending(arr, size, i + 1, 0);
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    int MIN = -10;
    int MAX = 10;

    int* arr = new int[SIZE];

    create(arr, SIZE, MIN, MAX, 0);
    print(arr, SIZE, 0);

    cout << "Кількість додатних елементів = " << countPositive(arr, SIZE, 0) << endl;

    sortAscending(arr, SIZE);
    print(arr, SIZE, 0);

    // Використовуємо шаблонні функції
    templateCreate(arr, SIZE, MIN, MAX, 0);
    templatePrint(arr, SIZE, 0);

    cout << "Кількість додатних елементів (шаблонні функції) = " << templateCountPositive(arr, SIZE, 0) << endl;

    templateSortAscending(arr, SIZE);
    templatePrint(arr, SIZE, 0);

    delete[] arr;

    return 0;
}
