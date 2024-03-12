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
        int i = p;
        int j = r;

        int pivot = nums.at(p);

        bool loopExecuted = false;
        while(i < j){
            loopExecuted = true;
            while(i < r && nums.at(i) <= pivot){
                i++;
            }
            while(j > p && nums.at(j) >= pivot){
                j--;
            }
            if(i < j){
                int temp = nums.at(i);
                nums.at(i) = nums.at(j);
                nums.at(j) = temp;
                i++;
                j--;
            }
        }
        //swap high with pivot
        if(loopExecuted){
            int temp = nums.at(j);
            nums.at(j) = pivot;
            nums.at(p) = temp;
        }
        return j;
    }
};

