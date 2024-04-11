class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // <= limit
        //brute force approach similar to sliding windows
        int maxLength = 1; //length of the subarray satisfying the property
        int windowLength = nums.size();
        for(int currLength = nums.size(); currLength > 1; currLength--){
            bool broken = false;
            for(int i = 0; i <= nums.size() - currLength; i++){
                //i represents the begin index of the current subarray with length currLength
                //retrieve the min and max values of the current subarray, if the difference is less than limit then subarray is ok
                int min = nums.at(i);
                int max = nums.at(i);
                for(int j = i; j < i + currLength; j++){
                    int currElt = nums.at(j);
                    if(currElt < min){
                        min = currElt;
                    }
                    else if(currElt > max){
                        max = currElt;
                    }
                }
                if(max - min <= limit && currLength > maxLength){
                    //update maxLength
                    maxLength = currLength;
                    broken = true;
                    break; //break the traversal for currLength subarray search
                }
            }
            if(broken){
                break; //maxLength is already set
            }
        }
        return maxLength;
    }
};
