#include <climits>

using namespace std;
class Kadane
{
    public:
    //Function to print the maximum contiguous subarray sum ending at each
    //position in the array and return the overall maximum.
    long long maximumSum(int arr[], int n)
    {
       //we will use tabulation
       //we can have a 2d array with size (n + 1)xn where row indices indicate the length of the subarray
       //and the column indices indicate the starting index for a particular subarray

       long long result = INT_MIN;

       long long** table = new long long*[n + 1];
       for(int i = 0; i < n + 1; i++){
            table[i] = new long long[n];
       }
       //no need to initialize the whole table, we won't use the garbage values
       int currLength = 1;
       //initialize length 1 subproblem solutions into the table and keep track of the result always
       for(int i = 0; i < n; i++){
           int curr = arr[i];
           table[currLength][i] = curr;
           if(curr > result){
               result = curr;
           }
       }
       while(currLength <= n){
           currLength++;
           //now perform the bottom up approach and obtain the result using DP
           for(int i = 0; i <= n - currLength; i++){
               int prevResult = table[currLength - 1][i]; //the result of the currLength - 1 length subarray sum
               //starting at the same index i
               int nextElt = arr[i + currLength - 1];
               int currResult = prevResult + nextElt;
               table[currLength][i] = currResult;
               if(currResult > result){
                    result = currResult;
                }

            }
       }
       for(int i = 0; i < n + 1; i++){
            delete[] table[i];
       }
       delete[] table;
       return result;
    }
};
