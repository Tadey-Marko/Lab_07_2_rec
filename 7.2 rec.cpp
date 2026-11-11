
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Створення матриці
int** makeMatrix(int rows, int cols) {
    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];
    return a;
}

// Заповнення матриці
void fillMatrix(int** a, int rows, int cols, int p = 0) {
    if (p == rows * cols) return;

    a[p / cols][p % cols] = -9 + rand() % 19;
    fillMatrix(a, rows, cols, p + 1);
}

// Виведення матриці
void printMatrix(int** a, int rows, int cols, int p = 0) {
    if (p == rows * cols) return;

    cout << setw(5) << a[p / cols][p % cols];
    if (p % cols == cols - 1) cout << endl;

    printMatrix(a, rows, cols, p + 1);
}

// Пошук мінімального елемента рядка
int minInRow(int* a, int n, int j, int minimum) {
    if (j == n) return minimum;

    if (a[j] < minimum)
        minimum = a[j];

    return minInRow(a, n, j + 1, minimum);
}

// Сума мінімальних елементів рядків
int sumRowMin(int** a, int rows, int cols, int i = 0) {
    if (i == rows) return 0;

    int minimum = minInRow(a[i], cols, 1, a[i][0]);

    return minimum + sumRowMin(a, rows, cols, i + 1);
}

int main() {
    srand(7);
    const int rows = 4, cols = 5;

    int** a = makeMatrix(rows, cols);
    fillMatrix(a, rows, cols);

    cout << "Matrix:\n";
    printMatrix(a, rows, cols);

    cout << "Sum = " << sumRowMin(a, rows, cols) << endl;

    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
