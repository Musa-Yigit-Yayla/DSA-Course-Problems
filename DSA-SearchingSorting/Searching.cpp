#include <iostream>

using namespace std;

class Searching{
public:
    int searchRotatedAndSorted(int arr[], int n, int x){
        int high = 0, low = n - 1;
        int mid = (low + high) / 2;
        while(high >= low){
            if(arr[mid] == x){
                return mid;
            }
            bool isLeftSorted = false;
            if(arr[low] < mid){
                //left half is sorted
                isLeftSorted = true;
            }
            if(x > arr[high]){
                //ignore the right half
            }
        }

    }

};
