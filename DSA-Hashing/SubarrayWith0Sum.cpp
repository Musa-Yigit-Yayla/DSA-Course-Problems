#include <unordered_set>

using namespace std;
class SubarrayWith0Sum{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n){
        //Your code here
        unordered_set<int> set;

        int subArraySum = 0;
        for(int i = 0; i < n; i++){
            subArraySum += arr[i];

            if(set.find(subArraySum) != set.end()){
                //we have encountered this sum before, so there has to be a subarray with 0 sum
                return true;
            }
            if(subArraySum == 0){
                return true;
            }
            set.insert(subArraySum);
        }
        return false;
    }
};
