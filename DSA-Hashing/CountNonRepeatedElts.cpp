#include <unordered_set>
#include <vector>

using namespace std;
class CountNonRepeatedElts{
    public:
    //Complete this function
    //Function to return the count of non-repeated elements in the array.
    int countNonRepeated(int arr[], int n){
        //Your code here
        unordered_set<int> set;
        vector<int> alreadyFound; // keeps track of the already found and checked elements inside the loop
        int counter = 0;

        for(int i = 0; i < n; i++){
            int curr = arr[i];
            if(set.find(curr) != set.end() && count(alreadyFound.begin(), alreadyFound.end(), curr) == 1){
                counter--;
                alreadyFound.push_back(curr);
            }
            else if(count(alreadyFound.begin(), alreadyFound.end(), curr) == 2){
                //this means that we have already seen this item before so just continue the loop
                //without altering the counter
                continue;
            }
            else{
                set.insert(curr);
                alreadyFound.push_back(curr);
                counter++;
            }
        }
        return counter;
    }
};
