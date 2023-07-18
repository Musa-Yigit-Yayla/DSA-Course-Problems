#include <iostream>
#include "InsertionSort.cpp"
using namespace std;

void printArray(int* arr, int size);
int main(){
    int arr[] = {24, 18, 38, 43, 14, 40, 1, 54};
    int arr1[5] = {4, 1, 3, 9, 7};
    InsertionSort is;
    is.quickSort(arr1, 0, 4);
    printArray(arr1, 5);
    return 0;
}
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
