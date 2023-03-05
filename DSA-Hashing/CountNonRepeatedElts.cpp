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
    // arr[]: input array
    // n: size of array
    //Function to return non-repeated elements in the array.
    vector<int> printNonRepeated(int arr[], int n){
        //Your code here
        unordered_set<int> set;

        vector<int> result;
        vector<int> originalArr(arr, arr + n);
        vector<int> eltsToRemove; // elements to not to be printed

        //add all the elements into the set, notice multiple elements will only be added once to the set
        for(int i = 0; i < n; i++){
            set.insert(arr[i]);
        }
        //Traverse the set, if the current element occurs once in the given array, then we add it to the result
        for(auto it: set){
            int curr = it; // might be problematic
            if(!(count(arr, arr + n, curr) > 1)){
                //no multiple occurences, add it to the result
                result.push_back(curr);
            }
            else{
                eltsToRemove.push_back(curr);
            }
        }

        //remove the elements which are not occuring in result from the original array
        for(int i = 0; i < eltsToRemove.size(); i++){
            int curr = eltsToRemove[i];
            //originalArr.remove(originalArr.begin(), originalArr.end(), curr);
            originalArr.erase(std::remove(originalArr.begin(), originalArr.end(), curr), originalArr.end());

        }

        //assign result to originalArr
        result = originalArr;
        return result;
    }
};
