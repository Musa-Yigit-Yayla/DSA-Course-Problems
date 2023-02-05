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
    pair<long, long> findRepeating(long *arr, int n){
        //code here
        int low = 0, high = n - 1;
        int mid;
        int repeatingElt = - 1;
        int noOfOccurences = n - (arr[n - 1] - arr[0]); // taken from the hint of the problem
        while(low <= high){
            mid = (low + high / 2);
            if((mid != 0 && mid != n - 1 && (arr[mid] == arr[mid - 1] || arr[mid] == arr[mid + 1]))){
            //|| ( mid == 0 && arr[mid + 1] == arr[mid]) || (mid == n - 1 && arr[mid - 1] == arr[mid])){
                repeatingElt = arr[mid];
            }
            else if(arr[mid] >= mid + arr[0]){ //condition taken from the hint of the problem
            //evaluate the right side if this is true
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(repeatingElt == -1){
            //no match has been found
            pair<long, long> newPair(-1, -1);
            return newPair;
        }
        else{
            pair<long, long> newPair(repeatingElt, noOfOccurences);
            return newPair;
        }

    }
};

