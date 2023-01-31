#include <iostream>

using namespace std;

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int mostOccuringElt = a[0];
        int maxOccurence = 1;

        int currElt;
        int prev = a[0];
        int currEltOccurence = 1;

        int arr[10000000];

        for(int i = 1; i < size; i++){
            currElt = a[i];
            if(prev != currElt){
                if(mostOccuringElt == currElt){
                    maxOccurence++;
                }
                arr[maxOccurence] = maxOccurence;
                currEltOccurence = 1;
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

        if((size / 2) < maxOccurence){
            return mostOccuringElt;
        }
        else{
            return - 1;
        }

    }
};
