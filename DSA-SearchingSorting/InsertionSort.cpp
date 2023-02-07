#include <iostream>

using namespace std;

class InsertionSort{
public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for(int i = 1; i < n - 1; i++){
            int key = arr[i];
            int insertionPos = 0;
            int j;
            bool hasBroken = false;
            for(j = 0; j < i; j++){
                if(arr[j] > key){
                    //place before the bigger elt
                    insertionPos = j;
                    hasBroken = true;
                    break;
                }
                else{

                }
            }
            if(!hasBroken){
                insertionPos = j;
            }
            int temp = arr[insertionPos];
            arr[insertionPos] = key;
            for(int j = insertionPos; j < n - 1; j++){
                if(j == insertionPos){
                    arr[j + 1] = temp;
                    temp = arr[j + 1];
                }
                //arr[j]
            }

        }
    }
};

