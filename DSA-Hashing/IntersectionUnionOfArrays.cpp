
#include <unordered_set>

using namespace std;
class IntersectionUnionOfArrays{
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        int result = 0;
        unordered_set<int> set1(a, a + n);
        unordered_set<int> set2(b, b + m);

        for(auto it: set2){
            if(set1.find(it) != set1.end()){
                result++;
            }
        }
        return result;
    }
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set<int> set(a, a + n);
        int result = set.size();

        for(int i = 0; i < m; i++){
            if(set.find(b[i]) == set.end()){
                set.insert(b[i]);
                result++;
            }
        }
        return result;
    }
};
