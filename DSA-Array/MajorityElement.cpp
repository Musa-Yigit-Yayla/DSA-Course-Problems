#include <iostream>

using namespace std;

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int length)
    {
        int mostOccuringElt = a[0];
        int maxOccurence = 1;

        int currElt;
        int prev = a[0];
        int currEltOccurence = 1;

        int arr[10000000] = {0};

        for(int i = 1; i < length; i++){
            currElt = a[i];
            if(prev != currElt){
                if(mostOccuringElt == currElt){
                    maxOccurence++;
                }
                arr[maxOccurence] = maxOccurence;
                currEltOccurence = arr[currEltOccurence] + 1;
            }
            else{
                currEltOccurence++;
            }
            if(currEltOccurence > maxOccurence){
                    maxOccurence = currEltOccurence;
                    mostOccuringElt = currElt;
            }

            prev = currElt;
        }

        if((length / 2) < maxOccurence){
            return mostOccuringElt;
        }
        else{
            return - 1;
        }

    }
    int leftIndex(int N, int arr[], int X){

        // Your code here
        int low = 0, high = N - 1;

        int index = -1;
        while(low <= high){
            int mid = (low + high) / 2;

            if(arr[mid] == X){
                index = mid;
                mid = high - 1;
                cout << "bool 0" << endl;
            }
            else if(arr[mid] > X){
                //search for right half
                high = mid - 1;

                cout << "bool 1" << endl;
            }
            else{
                low = mid + 1;
                cout << "bool 2" << endl;
            }
        }
        return - index;
    }
};
