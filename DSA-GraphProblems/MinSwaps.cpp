#include <vector>
/**
*This class uses the idea of regarding a given array as a graph in which each swapped element has a directed cycle from the initial pos
*to the destination pos. Therefore, we can count the number of min swaps required to sort the array by simply evaluating the number of cycles.
*/
using namespace std;
class MinSwaps{
public:
    //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>& nums){
	    vector<vector<int>> eltsWithIndex; //input elements with their index on the input array
	    //first column indicates the element itself whereas the second element's index
	    int numsSize = 0;
	    int ans = 0;
	    for(int i: nums){
	        vector<int> curr = {i, numsSize++};
	        eltsWithIndex.push_back(curr);
	    }
	    //sort the nums with respect to the first column
	    this->quickSort(eltsWithIndex, 0, numsSize - 1);
	    bool visit[numsSize];
	    for(int i = 0; i < numsSize; i++){
	        visit[i] = false;
	    }
	    for(int i = 0; i < numsSize; i++){
	        if(visit[i] || eltsWithIndex.at(i).at(0) == nums.at(i)){
	            continue;
	        }
	        int cycle_size = 0;
            int j = i;
            while (!visit[j]) {
                visit[j] = true;

                // move to next node
                j = eltsWithIndex.at(j).at(1);
                cycle_size++;
            }

            // Update answer by adding current cycle.
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }

        // Return result
        return ans;

	}
	//Quick sort a 2d array with the help of the partition algorithm with respect to 1st column at each row
	//low and high are inclusive
	void quickSort(vector<vector<int>>& arr, int low, int high){
	    if(low < high){
	        int mid = this->partition(arr, low, high);
	        this->quickSort(arr, low, mid);
	        this->quickSort(arr, mid + 1, high);
	    }
	}

	int partition(vector<vector<int>>& arr, int low, int high) {
    int pivot = arr[low][0];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= right && arr[left][0] <= pivot) {
            left++;
        }
        while (left <= right && arr[right][0] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(arr[left], arr[right]);
        }
    }

    // Swap pivot element to its correct position
    swap(arr[low], arr[right]);

    return right;
}
};
