#include <unordered_set>
#include <vector>

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
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int>& arr, int n ) {
        //code here
        long long int sum = 0;

        unordered_set<int> set;

        long long int subArraySum = 0;
        for(int i = 0; i < n; i++){
            subArraySum += arr[i];

            if(set.find(subArraySum) != set.end()){
                //we have encountered this sum before, so there has to be a subarray with 0 sum
                sum++;
            }
            if(subArraySum == 0 || arr[i] == 0){
                sum++;
            }
            set.insert(subArraySum);
        }
        return sum;
    }
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum){
        //Your code here
        //sum the whole array
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += arr[i];
        }
        unordered_map<int, int> map;
        int currSum = 0;
        int result = 0;
        int l = 0;
        for(int i = 0; i < n; i++){
            currSum += arr[i];
            if(currSum == sum){
                result++;
            }
            if(map.find(currSum - sum) != map.end()){
                result += map[currSum - sum];
                map[currSum - sum]++;
            }
            if(map.find(currSum) == map.end()){
                map.insert({currSum, 1});
            }
            else{
                map[currSum]++;
            }
        }
        return result;
    }
};
