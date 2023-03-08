
#include <unordered_set>

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int arr[], int b[], int n, int m) {
        // Your code goes here
        int result = 0;
        unordered_set<int> set;
        for(int i = 0; i < m; i++){
            //add the b elements to our unordered_set
            set.insert(b[i]);
        }
        for(int i = 0; i < n; i++){
            int curr = arr[i];
            if(find(set.begin(), set.end(), curr) != set.end()){
                result++;
            }
        }
        return result;
    }
