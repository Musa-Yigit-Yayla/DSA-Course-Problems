#include <vector>
#include <string>

using namespace std;
class LongestSubarrayWithEqual01{
public:
    //Receives a binary array and its length as inputs
    //Returns the longest length of the subarray with equal number of 0s and 1s if any exists
    //Returns -1 otherwise
    int findLongestNaive(int arr[], int n){
        int result = -1;
        string totalStr = "";
        vector<int> lengths;
        for(int i = 0; i < n; i++){
            totalStr += arr[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j+4){
                //check from i to j
                string sub = totalStr.substr(i, j + 1); // might be problematic with the indexing
                if(checkEquality(sub) == true){
                    lengths.push_back(sub.size());
                }
            }
        }
        //return the max from the the lengths if any exists
        for(int i = 0; i < lengths.size(); i++){
            int currLength = lengths.at(i);
            if(currLength > result){
                result = currLength;
            }
        }
        return result;
    }
    //Checks whether the given string satisfies the condition of containing equal number of 0s and 1s
    bool checkEquality(string& s){
        int noOf1s = 0;
        int noOf0s = 0;

        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(ch == '0'){
                noOf0s++;
            }
            else if(ch == '1'){
                noOf1s++;
            }
        }
        return noOf1s == noOf0s;
    }


};
