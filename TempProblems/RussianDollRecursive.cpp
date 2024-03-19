class RussianDollRecursive{
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //first sort the envelopes with respect to width, then we should find the maximum length ascending subarray wrt height
        quickSort(envelopes, 0, envelopes.size() - 1);
        /*for(vector<int> v: envelopes){
            cout << v.at(0) << ", " << v.at(1) << endl;
        }*/
        int currResult = 0;

        int prevHeight = envelopes.at(0).at(1);
        int prevWidth = envelopes.at(0).at(0);

        //following vector has 2 columns which contains start and end indexes of each sorted sublist specifying height property too
        vector<vector<int>> sortedSublists; //sorted wrt width in ascending order


        //now traverse the array once and track the max ascending height subarray
        for(int i = 1; i < envelopes.size(); i++){
            int currHeight = envelopes.at(i).at(1);
            int currWidth = envelopes.at(i).at(0);
            if(currWidth > prevWidth && currHeight > prevHeight){
                currResult++;
            }
            /*else if(currWidth == prevWidth){
                int minHeight = min(envelopes.at(i - 1).at(1), envelopes.at(i).at(1));
                    prevHeight = minHeight;
                    prevWidth = currWidth;
                    continue;
            }
            else if(currHeight == prevHeight){
                //take the smaller of widths which satisfy the greater than currMaxWidth
                if(currWidth > currMaxHeight &&)
            }*/
            else{
                //push back the current sublist
                vector<int> currIndexes;
                int prevIndex = i - 1;
                for(int j = prevIndex - currResult; j < i; j++){
                    currIndexes.push_back(envelopes.at(j).at(0));
                    currIndexes.push_back(envelopes.at(j).at(1));

                }
                sortedSublists.push_back(currIndexes);
                currResult = 1;
            }
            prevHeight = currHeight;
            prevWidth = currWidth;
        }
        //final check for the last insertion

        cout << sortedSublists.size() << endl;
        int maxSublistLength = this->findMaxSublist(sortedSublists, 0)
        return 0;

    }
    int findMaxSublist(vector<vector<int>>& list, int index, int prevIndex, int currMax){
        if(index == list.size() - 1){
            return currMax;
        }
        vector<int>& next = list.at(index + 1);
        vector<int>& curr = list.at(index);
        int nextFirstWidth = next.at(0);
        int nextFirstHeight = next.at(1);
        int currLastWidth = curr.at(curr.size() - 2);
        int currLastHeight = curr.at(curr.size() - 1);
        bool isNextAppendable = nextFirstWidth > currLastWidth && nextFirstHeight > currLastHeight;

        int v1 = 0;
        int v2 = 0;
        int v3 = 0;
        if(isNextAppendable){
            v1 = this->findMaxSublist(list, index + 1, index, currMax + next.size() / 2); // divide by 2 since we hold x, y coordinates in 1D
        }
        else{
            //skip the current index and start fresh from the nextIndex
        }
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
