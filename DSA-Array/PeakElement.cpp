#include <bits/stdc++.h>

using namespace std;

class PeakElement{
public:
    int peakElement(int arr[], int n){
       // Your code here
       int l = 0, r = n - 1;
       if(arr[l] >= arr[l + 1]){
           return l;
       }
       else if(arr[r] >= arr[r - 1]){
           return r;
       }
       while(l <= r){
        int mid = (l + r) / 2;
        if((mid == 0 && arr[mid + 1] <= arr[mid]) || ((mid != 0 && arr[mid - 1] <= arr[mid]) &&  (mid != n - 1 && arr[mid] <= arr[mid + 1])) || (arr[mid - 1] <= arr[mid] && mid == n - 1)){
            return mid;
        }
        else if( arr[mid] <= arr[mid - 1]  ){
            //search the left side
            r = mid - 1;
        }
        else{
         l = mid + 1;
        }
      }
    }
};

