#include <iostream>
#include "MaxHeapSort.cpp"

using namespace std;

int main()
{
    MaxHeapSort mhs;
    int arr[] = {4, 1, 3, 9, 7};
    int n = 5;
    mhs.heapSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}
