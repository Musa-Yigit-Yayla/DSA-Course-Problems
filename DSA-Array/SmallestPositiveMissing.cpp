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
    int floorSqrt(int x)
{
	// Base cases
	if (x == 0 || x == 1)
		return x;

	// Do Binary Search for floor(sqrt(x))
	int start = 1, end = x / 2, ans;
	while (start <= end) {
		int mid = (start + end) / 2;

		// If x is a perfect square
		int sqr = mid * mid;
		if (sqr == x)
			return mid;


		if (sqr <= x) {
			start = mid + 1;
			ans = mid;
		}
		else // If mid*mid is greater than x
			end = mid - 1;
	}
	return floor(sqrt(x));
}

};
