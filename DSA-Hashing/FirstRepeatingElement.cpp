#include <unordered_map>

using namespace std;
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int, int> myMap;

        for(int i = 0; i < n; i++){
            myMap[arr[i]]++;
        }
        for(auto it: myMap){
            if(it.second == 1){
                myMap.erase(it);
            }
        }
        int minIndex = INT_MAX;
        for(auto it: myMap){
            int index = find(arr, arr + n, it.first);
            if(index != n && index < minIndex ){
                minIndex = index;
            }
        }
        if(minIndex == INT_MAX){
            //no repeating elements
            return -1;
        }
        return minIndex + 1;
    }
};
