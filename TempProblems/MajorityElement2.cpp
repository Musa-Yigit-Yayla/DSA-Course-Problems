#include <vector>
#include <unordered_map>
#include <cmath>


using namespace std;
class MajorityElement2 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //n / 3 ceiltimes
        //we can use a hashmap unordered_map namely to count the occurence of each element
        unordered_map<int, int> occurenceMap;

        for(int curr: nums){
            occurenceMap[curr]++;
        }
        vector<int> result;
        //now we can simply retrieve the array elements which satisfy the counting condition
        int condition = ceil(nums.size() / 3);
        for(auto& it: occurenceMap){
            if(it.second > condition){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
