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
        for(int i = 0; i < n; i++){
            int curr = arr[i];
            if((myMap.at(curr) == 1)){

                myMap.erase((curr));
            }
        }
        int minIndex = INT_MAX;
        for(auto it: myMap){
            int* iterator = find(arr, arr + n, it.first);
            //int index = abs(distance(iterator, myMap.begin()));
            if(*iterator != n && *iterator < minIndex ){
                minIndex = *iterator;
            }
        }
        if(minIndex == INT_MAX){
            //no repeating elements
            return -1;
        }
        return minIndex + 1;
    }
};
