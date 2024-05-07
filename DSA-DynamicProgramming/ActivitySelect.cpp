#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class ActivitySelect{
public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n){
        //since we are given unsorted activities we must sort wrt to finish time
        this->quickSort(start, end, 0, n - 1);
        //now greedily choose the remaining activites in a for loop
        //greedy choice is the shortest amount of activity time
        vector<int> choiceIndexes = {1};
        for(int i = 1; i < n; i++){
            int latestIndex = choiceIndexes.at(choiceIndexes.size() - 1);

            //check if the lately included index is compatible with the next index
            if(end.at(latestIndex) <= start.at(i)){
                //include ith index since it has the earliest finish time amongst the rest
                choiceIndexes.push_back(i);
            }
        }
        return choiceIndexes.size();
    }
    //sort wrt end time vector
    void quickSort(vector<int>& start, vector<int>& end, int low, int high){
        if(low < high){
            int pIndex = this->partition(start, end, low, high);
            this->quickSort(start, end, low, pIndex);
            this->quickSort(start, end, pIndex + 1, high);
        }
    }
    int partition(vector<int>& start, vector<int>& end, int low, int high){
        //select pivot as low
        int pivot = end.at(low);
        int initPivotIndex = low;
        int pivotIndex = low;
        low++;
        while(low <= high){
            while(end.at(low) < pivot){
                low++;
            }
            while(end.at(high) > pivot){
                high--;
            }
            if(low < high){
                swap(end.at(low), end.at(high));
                swap(start.at(low), start.at(high));
            }
            else if(low == high){
                high--;
            }
        }
        swap(end.at(pivotIndex), end.at(high));
        swap(start.at(pivotIndex), start.at(high));
        return high;
    }
};
