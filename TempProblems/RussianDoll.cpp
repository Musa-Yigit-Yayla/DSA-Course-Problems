#include <vector>
#include <iostream>

using namespace std;
class RussianDoll{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //first sort the envelopes with respect to width, then we should find the maximum length ascending subarray wrt height
        quickSort(envelopes, 0, envelopes.size() - 1);
        /*for(vector<int> v: envelopes){
            cout << v.at(0) << ", " << v.at(1) << endl;
        }*/
        int maxResult = 0;
        int currResult = 1;
        int prevHeight = envelopes.at(0).at(1);
        //now traverse the array once and track the max ascending height subarray
        for(int i = 1; i < envelopes.size(); i++){
            int currHeight = envelopes.at(i).at(1);
            if(currHeight > prevHeight){
                currResult++;
            }
            else{
                //check whether we should update the maxResult
                if(maxResult < currResult){
                    maxResult = currResult;
                }
                currResult = 1;
            }
            prevHeight = currHeight;
        }
        //final check for maxResult
        if(maxResult < currResult){
            maxResult = currResult;
        }
        return maxResult;

    }
    void quickSort(vector<vector<int>>& envelopes, int start, int end){
        cout << "invoked quicksort with start and end " << start << ", " << end << endl;
        if(start < end){
            int pivotIndex = this->partition(envelopes, start, end);
            cout << pivotIndex;
            quickSort(envelopes, start, pivotIndex - 1);
            quickSort(envelopes, pivotIndex + 1, end);
        }
    }
    //partition wrt width
    int partition(vector<vector<int>>& envelopes, int start, int end){
        int pIndex = start;
        int pivot = envelopes.at(start).at(0);

        int i = start + 1;
        int j = end;
        while(i <= j){
            while(i <= end && envelopes.at(i).at(0) < pivot){
                //cout << "a";
                i++;
            }
            while(envelopes.at(j).at(0) > pivot){
                //cout << "b";
                j--;
            }
            if(i <= j){
                //swap curr elements at i and j
                swap(envelopes.at(i), envelopes.at(j));
                i++;
                j--;
            }
        }
        swap(envelopes.at(j), envelopes.at(pIndex));
        return j;
    }
};
