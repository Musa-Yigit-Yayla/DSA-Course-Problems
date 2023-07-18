#include <vector>
#include <cstddef>

using namespace std;
class FindTriplet{
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
            int curr = arr[i];
            bool broken = false;
            int j;
            for(j = 0; j < i; j++){
                if(j < i && arr[j] > curr){
                    //place curr at jth position and shift everything from j to i
                    broken = true;
                    break;
                }
            }
            if(broken){
                //now j stands for insertion pos
                int prev;
                bool counter = false;
                while(j < i){
                    if(counter == false){
                        prev = arr[j + 1];
                        arr[j + 1] = arr[j];
                    }
                    else{
                        int nextPrev = arr[j + 1];
                        arr[j + 1] = prev;
                        prev = nextPrev;
                    }
                    j++;
                    counter = true;
                }
            }
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
    //Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(int arr1[], int arr2[], int N, int M)
    {
        //Your code here
        vector<int> result;
        int low1 = 0, low2 = 0;
        /*bool isSwapped = false;
        if(M > N){
            int* temp = arr1;
            arr1 = arr2;
            arr2 = temp;
            int temp1 = N;
            N = M;
            M = temp1;
            isSwapped = true;
        }*/
        /*for(int i = 0; i < N && low2 < M; i++){
            int curr1 = arr1[i];
            int curr2 = arr2[low2];
            if(curr1 == curr2){
                result.push_back(curr1);
                low2++;
            }
            else if(curr2 < curr1){
                low2++;
            }
        }*/
        int* prev = nullptr;
        while(low1 < N && low2 < M){
            int curr1 = arr1[low1];
            int curr2 = arr2[low2];

            if(curr1 < curr2){
                low1++;
            }
            else if(curr1 == curr2){
                if(prev == NULL){
                    result.push_back(curr1);
                }
                else if(prev != NULL && *prev != curr1){
                    result.push_back(curr1);
                }
                prev = arr1 + low1;
                low1++;
                low2++;
            }
            else{
                low2++;
            }
        }
        if(result.size() == 0){
            result.push_back(-1);
        }
        /*if(isSwapped){
            int* temp = arr1;
            arr1 = arr2;
            arr2 = temp;
        }*/
        return result;
    }
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two sorted arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        int low1 = 0;
        int low2 = 0;
        vector<int> result;
        int prev;
        bool isLoopExecuted = false;
        while(low1 < n && low2 < m){
            int curr1 = arr1[low1];
            int curr2 = arr2[low2];

            if(!isLoopExecuted){
                //don't check prev
                if(curr1 == curr2){
                    result.push_back(curr1);
                    prev = curr1;
                    low1++;
                    low2++;
                }
                else if(curr1 < curr2){
                    result.push_back(curr1);
                    prev = curr1;
                    low1++;
                }
                else{
                    result.push_back(curr2);
                    prev = curr2;
                    low2++;
                }
                isLoopExecuted = true;
            }
            else{
                //same procedure but if the element to be pushed equates to prev then don't add to vector
                if(curr1 == curr2){
                    if(prev != curr1)
                        result.push_back(curr1);
                    prev = curr1;
                    low1++;
                    low2++;
                }
                else if(curr1 < curr2){
                    if(prev != curr1)
                        result.push_back(curr1);
                    prev = curr1;
                    low1++;
                }
                else{
                    if(prev != curr2)
                        result.push_back(curr2);
                    prev = curr2;
                    low2++;
                }
            }

        }
        //add the remaining elements if one of the arrays is not exhausted yet
        while(low1 < n){
            int curr1 = arr1[low1];
            if(prev != curr1)
                result.push_back(curr1);
            prev = curr1;
            low1++;
        }
         while(low2 < m){
            int curr2 = arr2[low2];
            if(prev != curr2)
                result.push_back(curr2);
            prev = curr2;
            low2++;
        }
        return result;
    }
};
