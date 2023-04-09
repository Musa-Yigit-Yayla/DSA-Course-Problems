#include <iostream>
#include "Q7.cpp"

using namespace std;

int main(){
    Q7 q7;

    int arr[] = {45, 2, 6, 68, 12, 10, 3, 2, 10, 21, 5};
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

    delete[] arr1;
    delete[] arr2;
    return 0;
}
