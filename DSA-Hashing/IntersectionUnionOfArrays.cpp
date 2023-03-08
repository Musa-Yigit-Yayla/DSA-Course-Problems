
#include <unordered_set>

class IntersectionUnionOfArrays{
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int arr[], int b[], int n, int m) {
        // Your code goes here
        int result = 0;
        unordered_set<int> set(b, b + m);

        for(int i = 0; i < n; i++){
            int curr = arr[i];
            if(set.find(curr) != set.end()){
                result++;
            }
        }
        return result;
    }
};
