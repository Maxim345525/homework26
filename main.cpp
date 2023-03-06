#include <iostream>
using namespace std;
void deleteColumn(int** arr, int rows, int cols, int colIndex) {
    for (int i = 0; i < rows; i++) {
        for (int j = colIndex; j < cols - 1; j++) {
            arr[i][j] = arr[i][j + 1]; 
        }
    }
    cols--;
    int** newArr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newArr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newArr[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = newArr;
}
int main() {
    int rows = 3;
    int cols = 4;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    deleteColumn(arr, rows, cols, 2);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
}