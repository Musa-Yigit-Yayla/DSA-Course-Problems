#include <vector>
#include <iostream>

using namespace std;
class HIndex {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1){
            int result = citations.at(0) >= 1;
            return result;
        }
        /*else if(citations.size() == 2){
            int result = 0;
            if(citations.at(0) >= 2 && citations.at(1) >= 2){
                result = 2;
            }
            else if(citations.at(0) == 1 || citations.at(1) == 1){
                result = 1;
            }
            return result;
        }*/

        //first we should apply quicksort to increase the time complexity of our solution
        this->quickSort(citations, 0, citations.size() - 1);
        int maxH = 0; //result can be 0 at worst case where no citations have been made

        //find the first maximum array element which is less than or equal to arr.length and its index
        int candidate;
        int candidateIndex;
        int largerSizeCount = 0; //elements which we have iterated over and are bigger than the size of the array
        int j;
        for(j = citations.size() - 1; j >= 0; j--){
            if(citations.at(j) > citations.size()){
                largerSizeCount++;
            }
            else{
                candidate = citations.at(j);
                candidateIndex = j;
                break;
            }
        }
        if(j < 0){
            //special case where all our candidates appear to be larger than the array size
            //result must be the array size
            maxH = citations.size();
        }
        else{


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
        }
        return maxH;
    }
    void quickSort(vector<int>& arr, int q, int r){
        if(q < r){
            int pIndex = this->partition(arr, q, r);
            this->quickSort(arr, q, pIndex);
            this->quickSort(arr, pIndex + 1, r);
        }
    }
    int partition(vector<int>& arr, int q, int r) {
        int pivotIndex = q;
        int pivot = arr[pivotIndex];

        int i = q - 1;
        int j = r + 1;

        while(true){
            do{
                i++;
            } while(arr[i] < pivot);

            do{
                j--;
            } while(arr[j] > pivot);

            if(i >= j) {
                //int temp = arr.at(pivotIndex);
                //arr.at(pivotIndex) = arr.at(j);
                //arr.at(j) = temp;
                return j; // Return partition index
            }

            // Swap elements
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
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
