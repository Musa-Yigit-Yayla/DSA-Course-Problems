#include <iostream>
#include <cmath>

using namespace std;
class InsertionSort{
public:
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
    //This method belongs to CS202 HW1
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
   void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low < high){
            int pivotIndex = this->partition(arr, low, high);

            this->quickSort(arr, low, pivotIndex - 1);
            this->quickSort(arr, pivotIndex + 1, high);
        }
    }


    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivotIndex = low;
       int pivot = arr[low];
       while(low < high){
           while(arr[low] <= pivot){
               low++;
               if(low > high){
                   break;
               }
           }
           int currLow = arr[low];
           while(arr[high] >= pivot){
               high--;
               if(high < low){
                   break;
               }
           }
           //swap these two
           if(high > low){
            int temp = currLow;
            arr[low] = arr[high];
            arr[high] = temp;
           }
       }
       //place pivot at high index attained after loop execution
       arr[pivotIndex] = arr[high];
       arr[high] = pivot;
       return high;
    }
    //Algorithm belongs to Carrano Henry book
    /*void radixSort(int arr[], int n, int d){
        for(int j = d; j > 0; j--){
            //since there are 10 digits we initialize 10 empty groups with size 10
            int groups[10][n] = {0};
            int counters[10] = {0};

            for(int i = 0; i < n; i++){
                int currDigit = arr[i] % (pow(10, d- j + 1))
                int k = currDigit;
                groups[k][counter[k]++] = arr[i];
            }
            int count = 0;
            int* counterPtr = counters;
            while(count < n && counterPtr != NULL){
                else if(*counterPtr == 0){
                    counterPtr++;
                }
                else{
                    for(int i = 0; i < *counterPtr; i++){
                        arr[count++] = groups[counterPtr][i];
                    }
                }
            }
        }
    }*/
};

