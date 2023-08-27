#include <iostream>
#include "MaxHeapSort.cpp"

using namespace std;

int main()
{
    MaxHeapSort mhs;
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    mhs.heapSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}
