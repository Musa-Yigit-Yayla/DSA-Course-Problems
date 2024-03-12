#include <climits>

class SmallestRange2 {
public:
    /*int smallestRangeII(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return 0;
        }

        int result =  INT_MAX;
        //brute force approach
        for(int i = 0; i < nums.size(); i++){
            int newI = nums.at(i) + k;
            for(int j = 0; j < nums.size(); j++){
                if(j == i){
                    continue;
                }
                int currJ = nums.at(j) + k;
                if(abs(currJ - newI) < result){
                    result = abs(currJ - newI);
                }
                currJ = nums.at(j) - k;
                if(abs(currJ - newI) < result){
                    result = abs(currJ - newI);
                }
            }
        }
        for(int i = 0; i < nums.size(); i++){
            int newI = nums.at(i) - k;
            for(int j = 0; j < nums.size(); j++){
                if(j == i){
                    continue;
                }
                int currJ = nums.at(j) + k;
                if(abs(currJ - newI) < result){
                    result = abs(currJ - newI);
                }
                currJ = nums.at(j) - k;
                if(abs(currJ - newI) < result){
                    result = abs(currJ - newI);
                }
            }
        }
        return result;
    }*/
    int smallestRangeII(vector<int>& nums, int k){
        int result = this->recursiveMinDiff(nums, k, 0);
        return result;
    }
    int recursiveMinDiff(vector<int>& nums, int k, int index){
        if(index < nums.size()){
            //calculate both cases of recursive step and return the minimum to the caller
            vector<int> c1 = nums;
            vector<int> c2 = nums;

            c1[index] -= k;
            c2[index] += k;
            int r1 = recursiveMinDiff(c1, k, index + 1);
            int r2 = recursiveMinDiff(c2, k, index + 1);

            return min(r1, r2);
        }
        else{ //base case
            //calculate the difference between min and max values and return to the caller
            int min = nums.at(0);
            int max = nums.at(0);

            for(int i = 0; i < nums.size(); i++){
                int curr = nums.at(i);

                if(curr < min){
                    min = curr;
                }
                else if(curr > max){
                    max = curr;
                }
            }
            return max - min;
        }
    }
};
