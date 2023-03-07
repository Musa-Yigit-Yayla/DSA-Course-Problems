#include <unordered_map>
#include <algorithm>

using namespace std;
class FirstRepeatingElement{
  public:
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
        /*for(auto it: myMap){
            cout << "Key: " << it.first << " Value: " << it.second << endl;
        }*/
        for(auto it: myMap){
            //int* iterator = find(arr, arr + n, it.first);
            int* index = find(arr, arr + n, it.first);
            int indexValue = (index - arr);
            //int index = abs(distance(iterator, myMap.begin()));
            if(indexValue != n && indexValue < minIndex ){
                minIndex = indexValue;
            }
        }
        if(minIndex == INT_MAX){
            //no repeating elements
            return -1;
        }
        return minIndex + 1;
    }
};
