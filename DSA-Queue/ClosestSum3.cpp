#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
class ClosestSum3 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //make a linear search for the closest elements one by one compared to the following elements
        //target / 3, target / 3, target / 3 + (target % 3) //CAREFUL TO MOD WHEN NEGATIVE
        //sum the found values and return
        vector<int> closeElts; //holds the result values to be summed
        vector<int> usedIndexes;

        int currKey = target / 3;
        int currClosest = this->getClosest(nums, currKey, usedIndexes);
        closeElts.push_back(currClosest);

        currKey = target / 3;
        currClosest = this->getClosest(nums, currKey, usedIndexes);
        closeElts.push_back(currClosest);

        if(target < 0){
            //negative case where we add the -(positive_mod)
            int posTarget = 0 - target;
            currKey = target / 3 - ((posTarget) % 3);
        }
        else{
            currKey = target / 3 + (target % 3);
        }
        currClosest = this->getClosest(nums, currKey, usedIndexes);
        closeElts.push_back(currClosest);

        int result = 0;
        for(int curr: closeElts){
            result += curr;
        }
        return result;
    }
    int getClosest(vector<int>& nums, int key, vector<int>& usedIndexes){
        int currClosest = pow(10, 6);
        int currClosestIndex = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(count(usedIndexes.begin(), usedIndexes.end(), i) == 0){
                int currElt = nums.at(i);
                if(abs(currElt - key) < abs(currClosest - key)){
                    currClosest = currElt;
                    currClosestIndex = i;
                }
            }
        }
        usedIndexes.push_back(currClosestIndex); //keep track of the used indexes
        return currClosest;
    }
};
