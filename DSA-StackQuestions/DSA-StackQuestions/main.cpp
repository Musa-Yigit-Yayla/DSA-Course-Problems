#include <iostream>
#include "GetMinAtPop.cpp"


using namespace std;

int main()
{
    GetMinAtPop gmap;
    int arr[12] = {20, 59, 42, 94, 12, 46, 51, 40, 67, 41, 7, 56};
    stack<int> newStack = gmap._push(arr, 12);
    gmap._getMinAtPop(newStack);
    return 0;
}
