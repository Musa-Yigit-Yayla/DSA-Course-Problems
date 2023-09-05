#include <iostream>
#include <cstddef>
//#include "MaxHeapSort.cpp"
#include "BTFromParentArr.cpp"
//#include "NumberOfIslands.cpp"

using namespace std;

int main()
{
    /*MaxHeapSort mhs;
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

    BTFromParentArr* btfpa = new BTFromParentArr();
    Node* result = nullptr;
    int arr[] = {-1,0,0,1,1,3,5};
    int n = 7;
    result = btfpa->createTree(arr, n);
    cout << result->data;
    delete btfpa;
    return 0;
}
