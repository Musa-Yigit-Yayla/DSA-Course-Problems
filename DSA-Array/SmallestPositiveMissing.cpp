#include <algorithm>
#include <bits/stdc++.h>
class SmallestPositiveMissing{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // Your code here
        //1-)Segregate the array
        partition(arr, n);

        //find index of the first positive element
        int firstPosIndex = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                firstPosIndex = i;
                break;
            }
        }
        int i = 1;
        int smallestSoFar = arr[0];
        int secondSmallestSoFar = arr[0];
        bool enteredLoop = false;
        for(int j = firstPosIndex; j < n && j != -1 && arr[j] > 0; j++){
            enteredLoop = true;
            if(arr[j] > i){
                if(smallestSoFar > arr[j]){
                    secondSmallestSoFar = smallestSoFar;
                    smallestSoFar = arr[j];
                }
                else if(secondSmallestSoFar > arr[j]){
                    secondSmallestSoFar = arr[j];
                }
                //return i;
            }
            i++;
        }
        if(!enteredLoop)
         return i;
        else{
            if(secondSmallestSoFar - smallestSoFar == 1){
                return secondSmallestSoFar + 1;
            }
            else{
                return smallestSoFar + 1;
            }
        }
    }

    void partition(int arr[], int n){
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                if (i != j)
                    swap1(&arr[i], &arr[j]);
                j++;
            }
        }
    }
    void swap1(int* n1, int* n2){
        int temp = *n1;
        n1 = n2;
        n2 = &temp;
    }
    class Solution{
  public:
    long long int floorSqrt(long long int x)
    {
        // Your code goes here
        if(x == 0 || x == 1){
            return x;
        }
        int l = 1, r = x / 2;
        int ans;
        while(l <= r){
            int mid = (l + r) / 2;
            if(pow(x, 2) >= mid){
                ans = mid;
                l = mid + 1;
            }
            else if(pow(mid, 2) > x){
                //search for the left half
                r = mid - 1;
            }
        }
        return ans;
    }
};
};
