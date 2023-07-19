#include <vector>

using namespace std;
class SortAbsDifference{
public:
    // A[]: input array
    // N: size of array
    //Function to sort the array according to difference with given number.
    void sortABS(int A[],int N, int k)
    {
       //Your code here
       int initialArr[N];
       int differenceArr[N];
       //map<int, int> map;
       //bool isUsed[N] = {false}; // array for holding whether we have used an element at a certain index
       for(int i = 0; i < N; i++){
           int currDiff = abs(A[i] - k);
           differenceArr[i] = currDiff;
           initialArr[i] = A[i];
           /*if(map.count(A[i]) == 0){
               map.insert({A[i], currDiff});
           }*/
       }/*
       int arr[N]; // resulting array
       //Use unordered map, link every array element with their corresponding difference
       //sort the difference arr
       sort(differenceArr, differenceArr + N);
       for(int i = 0; i < N; i++){

       }
       //traverse the sorted difference arr and if we have an element same with previous collect it
       int prev;
       for(int i = 0; i < N; i++){
           if(i == 0){

           }
       }*/
       //Subsequently retrieve key's that have same difference value
       //Store those keys in a vector with the same order they appear in original array
       //Accordingly make required swaps
       this->quickSort(differenceArr, A, 0, N - 1);
       //traverse the sorted differenceArr
       int prevDiff = differenceArr[0];
       for(int i = 1; i < N; i++){
           int currDiff = differenceArr[i];
           if(currDiff = prevDiff){
               vector<int> elements = this->getKeys(initialArr, differenceArr, N, currDiff);
               i -= 1;
               for(int j = 0; j < elements.size(); j++, i++){
                   A[i] = elements.at(j);
               }
           }
           int prevDiff = currDiff;
       }
    }
    void quickSort(int arr1[], int arr2[], int low, int high)
    {
        // code here
        if(low < high){
            int pivotIndex = this->partition(arr1, arr2, low, high);

            this->quickSort(arr1, arr2, low, pivotIndex - 1);
            this->quickSort(arr1, arr2, pivotIndex + 1, high);
        }
    }

    //arr1 and arr2 have same sizes but different contents
    //partition second array wrt to first array
    int partition (int arr1[], int arr2[], int low, int high)
    {
       // Your code here
       int pivotIndex = low;
       int pivot = arr1[low];
       int pivot2 = arr2[low];
       while(low < high){
           while(arr1[low] <= pivot){
               low++;
               if(low > high){
                   break;
               }
           }
           int currLow = arr1[low];
           while(arr1[high] >= pivot){
               high--;
               if(high < low){
                   break;
               }
           }
           //swap these two
           if(high > low){
            int temp = currLow;
            arr1[low] = arr1[high];
            arr1[high] = temp;

            temp = arr2[low];
            arr2[low] = arr2[high];
            arr2[high] = temp;
           }
       }
       //place pivot at high index attained after loop execution
       arr1[pivotIndex] = arr1[high];
       arr1[high] = pivot;

       arr2[pivotIndex] = arr2[high];
       arr2[high] = pivot2;
       return high;
    }
    //When we have multiple elements in our original array attaining same absolute difference,
    //we will invoke this method so as to obtain those elemens in the order they appear in our array
    vector<int> getKeys(int const arr[], int const differenceArr[], int n, int value){
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(differenceArr[i] == value){
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};
