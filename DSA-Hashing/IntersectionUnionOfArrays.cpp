
#include <unordered_set>

class IntersectionUnionOfArrays{
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        int result = 0;
        unordered_set<int> set1(a, a + n);
        unordered_set<int> set2(b, b + m);

        /*for(int i = 0; i < set2.size(); i++){
            int curr = set2.at(i);
            if(set1.find(curr) != set1.end()){
                result++;
            }
        }*/
        for(auto it: set2){
            if(set1.find(it) != set1.end()){
                result++;
            }
        }
        return result;
    }
};
