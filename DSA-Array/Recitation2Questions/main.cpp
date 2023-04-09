#include <iostream>
#include "Q7.cpp"
#include <cmath>

using namespace std;

int main(){
    Q7 q7;

    int arr[] = {45, -2, 6, -68, -12, 10, 3, 2, 10, 21, -5};
    int n = 11;
    int* arr1 = nullptr;
    int* arr2 = nullptr;

    int i1 = 3;
    int i2 = 7;

    int n1 = i2 - i1 + 1;
    int n2 = n - n1;

    q7.splitArray(arr, 11, arr1, arr2, i1, i2);
    q7.displayArr(arr1, n1);
    q7.displayArr(arr2, n2);
    q7.displayArr(arr, n);

    int resultSize = n;
    int* arr3 = q7.selectNegatives(arr, n, resultSize);

    q7.displayArr(arr3, resultSize);

    const int r = 5;
    const int c = 4;
    int matrix[5][4] = {{1, 2, 3, 2}, {3, -1, 1, -1}, {2, 1, 2, -2}, {1, 2, 5, 2}, {4, 1, 3, 3}};
    int* arr4 = q7.rowSum(matrix, r, c);
    q7.displayArr(arr4, r);

    int* dynamicMatrix = new int[r * c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            *(dynamicMatrix + i * c + j)  = (int)(rand() % (5));
        }
    }

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] dynamicMatrix;

    return 0;
}
