class LargestDivisibleSubset {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //we can use a recursive helper method to solve the problem
        vector<int> result;
        result = this->getLargestResult(nums, 0, result);
        return result;
    }
    vector<int> getLargestResult(vector<int>& nums, int i, vector<int> currSubset){

        if(i == nums.size()){
            return currSubset; //base case
        }
        /*vector<int> result0;
        vector<int> result1;
        if(currSubset.size() == 0){
            vector<int> v1 = currSubset;
            v1.push_back(nums.at(i)); //push the curr Index
            result0 = this->getLargestResult(nums, i + 1, v1);
            vector<int> intermediateResult1 = this->getLargestResult(nums, i + 1, currSubset);
        }*/
        vector<int> res1;

        if(currSubset.size() == 0){
            //taking the first element or disregarding it without condition checking

            res1.push_back(nums.at(i));
            res1 = this->getLargestResult(nums, i + 1, res1);


        }
        else{
             bool applicable = true;
            int currIndexElt = nums.at(i);
            for(int j = 0; j < currSubset.size() && applicable; j++){
                int currElt = currSubset.at(j);
                if(!(currElt % currIndexElt == 0 || currIndexElt % currElt == 0)){
                    applicable = false;
                }
            }
            if(applicable){
                //branch into the recursive step where we we can include this element too
                vector<int> v1 = currSubset;
                v1.push_back(currIndexElt); //push the currIndexElt
                res1 = this->getLargestResult(nums, i + 1, v1);
            }
        }

        //don't forget to branch into the recursive step where the current element is not taken
        vector<int> res2 = this->getLargestResult(nums, i + 1, currSubset);

        vector<int> result = res1;
        if(res2.size() > result.size()){
            result = res2;
        }
        return result;

        /*if(nums.at(i) % nums.at(i + 1) == 0 || nums.at(i + 1) % nums.at(i) == 0){
            vector<int> v1 = currSubset;
            v1.push_back(nums.at(i + 1)); //push the next index
        }*/

    }
};
