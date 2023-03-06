#include<iostream>
using namespace std;
void addColumn(int** arr, int rows, int cols, int colIndex, int* newCol) {
    int** newArr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newArr[i] = new int[cols + 1];
    }
    for (int i = 0; i < rows; i++) {
        int col = 0;
        for (int j = 0; j < cols + 1; j++) {
            if (j == colIndex) {
                newArr[i][j] = newCol[i];
            }
            else {
                newArr[i][j] = arr[i][col];
                col++;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;
}
void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int rows = 3;
    int cols = 3;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j;
        }
    }
    int newCol[] = { 0, 1, 2 };
    addColumn(arr, rows, cols, 1, newCol);
    printArray(arr, rows, cols + 1);
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}