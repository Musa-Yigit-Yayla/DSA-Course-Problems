#include <vector>

using namespace std;
class SortQuick{
public:
    vector<int> sortArray(vector<int>& nums) {
        //apply quick sort
        this->sortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
    void sortHelper(vector<int>& nums, int begin, int end){
        if(begin < end){
            int pivotIndex = this->h_partition(nums, begin, end);
            sortHelper(nums, begin, pivotIndex - 1);
            sortHelper(nums, pivotIndex + 1, end);
        }
    }
    int h_partition(vector<int>& nums, int p, int r){
        int i = p + 1;
        int j = r;

        int pivot = nums.at(p);

        while(i < j){
            while(nums.at(i) < pivot && i < r){
                i++;
            }
            while(nums.at(j) > pivot && j > p){
                j--;
            }
            if(i < j){
                int temp = nums.at(i);
                nums.at(i) = temp;
                nums.at(j) = temp;
            }
        }
        //swap high with pivot

        int temp = nums.at(j);
        nums.at(j) = pivot;
        nums.at(p) = temp;

        return j;
    }
};
