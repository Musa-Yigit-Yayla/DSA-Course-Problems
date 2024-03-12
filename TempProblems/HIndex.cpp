class HIndex {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1){
            int result = citations.at(0) >= 1;
            return result;
        }

        //first we should apply quicksort to increase the time complexity of our solution
        this->quickSort(citations, 0, citations.size() - 1);
        int maxH = 0; //result can be 0 at worst case where no citations have been made

        //find the first maximum array element which is less than or equal to arr.length and its index
        int candidate;
        int candidateIndex;
        for(int j = citations.size() - 1; j >= 0; j--){
            if(citations.at(j) <= citations.size()){
                candidate = citations.at(j);
                candidateIndex = j;
                break;
            }
        }
        bool found = false;
        while(!found){
            if(citations.size() - candidateIndex >= candidate){
                maxH = candidate;
                found = true;
                break;
            }
            else if(candidateIndex >= 0){
                candidate = citations.at(--candidateIndex);
            }
            else{
                break; //terminate
            }
        }
        return maxH;
    }
    void quickSort(vector<int>& arr, int begin, int end){
        if(begin < end){
            int pIndex = this->partition(arr, begin, end);
            this->quickSort(arr, begin, pIndex - 1);
            this->quickSort(arr, pIndex + 1, end);
        }
    }
    int partition(vector<int>& arr, int begin, int end){
        vector<int> vecPivot = this->getPivot(arr, begin, end);
        int pivot = vecPivot.at(0);
        int pivotIndex = vecPivot.at(1);

        int i = begin;
        int j = end;

        bool done = false;
        while(!done){
            //start from right search for an element smaller than or equal to pivot
            while(j >= begin && arr[j] > pivot){
                j--;
            }
            //perform the similar task for the lefthand side
            while(i <= end && arr[i] < pivot){
                i++;
            }
            if(i < j){
                //swap elements
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                i++;
                j--;
            }
            else{
                done = true;
            }
        }
        //lastly swap the pivot element with high index (namely j)
        int temp = arr[pivotIndex];
        arr[pivotIndex] = arr[j];
        arr[j] = temp;

        return j;
    }
    vector<int> getPivot(vector<int>& arr, int i, int j){
        vector<int> result;

        int midIndex = (i + j) / 2;
        int first = arr[i], mid = arr[midIndex], last = arr[j];
        int maxElt = max(first, max(mid, last));
        int minElt = min(first, min(mid, last));

        if(first != maxElt && first != minElt){
            result.push_back(first);
            result.push_back(i);
        }
        else if(mid != maxElt && mid != minElt){
            result.push_back(mid);
            result.push_back(midIndex);
        }
        else{
            result.push_back(last);
            result.push_back(j);
        }
        return result;
    }
};
