#include <unordered_set>
#include <iostream>

using namespace std;

class HashingForPair{
public:
    // You need to complete this function.
// Function to check if there is a pair with the given sum in the array.
    int sumExists(int arr[],  const int N, const int sum) {
        // Your code here.
        unordered_set<int> set;
        //Place all the elements in the set
        for(int i = 0; i < N; i++){
            set.insert(arr[i]);
        }
        for(int i = 0; i < N; i++){
            int curr = arr[i];
            if(set.find(sum - curr) != set.end()){
                return 1;
            }
        }
        return 0;
    }

};
