#include <vector>

using namespace std;
class SortQuicker{
public:

    vector<int> sortArray(vector<int>& nums) {
        //apply quick sort
        this->sortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
    void sortHelper(vector<int>& nums, int begin, int end){
        if(begin < end){
            int pivotIndex = this->partition(nums, begin, end);
            sortHelper(nums, begin, pivotIndex - 1);
            sortHelper(nums, pivotIndex + 1, end);
        }
    }
    int partition(vector<int>& nums, int first, int last){
        int pivot = nums.at(first);
        int pivotIndex = first;
        int j = last;
        int i = first + 1;

        bool done = false;
        while(!done){
            //choose the first smaller than pivot elt from right side
            while(j >= first && nums.at(j) > pivot){
                j--;
            }
            while(i <= last && nums.at(i) < pivot){
                i++;
            }
            if(i < j){
                int temp = nums.at(j);
                nums.at(j) = nums.at(i);
                nums.at(i) = temp;

                i++;
                j--;
            }
            else{
                done = true;
            }
        }
        //interchange high index with pivot index
        int temp = nums.at(first);
        nums.at(first) = nums.at(j);
        nums.at(j) = temp;

        return j;
    }
};


