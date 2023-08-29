#include <iostream>
#include "MaxHeapSort.cpp"
//#include "NumberOfIslands.cpp"

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
    NumberOfIslands noi;
    /*vector<vector<char>> input{{{0,1},{1,0},{1,1},{1,0}}};
    int result = noi.numIslands(input);
    cout << result << endl;*/

    return 0;
}
