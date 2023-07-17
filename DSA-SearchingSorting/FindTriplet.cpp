#include <vector>
#include <cstddef>

using namespace std;
class Solution{
  private:
    int* array = nullptr;
    int size;
  public:
    //Function to find triplets with zero sum.
    bool findTriplets2(int arr[], int n)
    {
        //Your code here
        int cc = 0, mc = 0;
        this->bubbleSort(arr, n, cc, mc);
        for(int i = 0; i <= n - 3; i++){
            if(arr[i] + arr[i + 1] + arr[i + 2] == 0){
                return true;
            }
        }
        return false;

    }
    bool findTriplets(int arr[], int n){
        this->array = arr;
        this->size = n;
        vector<int> vec;
        return this->helper(vec, 0);
    }
    void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
        bool sorted = false; //false when swaps occur
        int pass = 1; //start pass from 1 since at most n - 1 passes may occur
        int n = size;
        while(!sorted && (pass < n)){
            sorted = true;
            for(int index = 0; index < n - pass; index++){

                int nextIndex = index + 1;
                if(arr[index] > arr[nextIndex]){
                    int temp = arr[index];
                    arr[index] = arr[nextIndex];
                    arr[nextIndex] = temp;
                    sorted = false; //signal exchange
                    moveCount += 3; // 3 operations for swapping
                }
                compCount++;
            }
            pass++;
        }
    }
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for(int i = 1; i < n; i++){
            int key = arr[i];
            int insertionPos;//position for the key to be inserted in the sorted part
            //Elements before i are assumed to be sorted already
            bool insertionPosFound = false;
            for(int j = 0; j < i; j++){
                if(arr[j] > key){
                    //insert right before the first bigger element
                    insertionPos = j;
                    insertionPosFound = true;
                    break;
                }
            }
            if(!insertionPosFound){
                insertionPos = i;
            }

            //insert the element
            int temp = arr[insertionPos];

            for(int j = insertionPos, counter = 0; j < i; j++, counter++){
                /*int currElt = arr[j];
                if(counter == 0){
                    arr[j] = temp;
                    temp = currElt;
                }*/
                arr[j + 1] = arr[j];
                //arr[j + 1] = arr[j];
                counter++;
            }
            arr[insertionPos] = key;

        }
    }
    bool helper( vector<int> selections, int currIndex){
        //base cases
        if(selections.size() == 3){
            int sum = 0;
            for(int i = 0; i < selections.size(); i++){
                sum += selections.at(i);
            }
            if(sum == 0){
                return true;
            }
            return false;
        }
        else if(currIndex >= this->size){
            return false;
        }
        //either select the current element from array, which is a private data field, or proceed
        //without any selection
        vector<int> copy1 = selections; // deep copy the current vector
        vector<int> copy2 = selections; //similarly deep copy again
        copy1.push_back(this->array[currIndex]);
        if(this->helper(copy1, currIndex + 1)){
            return true;
        }
        else if(this->helper(copy2, currIndex + 1)){
            return true;
        }
        return false;
        //two way recursion
    }
};
