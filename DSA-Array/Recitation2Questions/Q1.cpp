#include <string>

using namespace std;

//Returns an array which contains min and max values in the given array respectively
//Also set the min max values accordingly
int* minMax(int arr[],int& min, int& max, int n){
    min = INT_MAX;
    max = INT_MIN;

    for(int i = 0; i < n; i++){
        int curr = arr[i];

        if(min > curr){
            min = curr;
        }
        if(max < curr){
            max = curr;
        }
    }

    int* newArr = new int[2]; //dynamic array because otherwise it will get deleted by the end of the block
    newArr[0] = min;
    newArr[1] = max;

    return newArr;
}
