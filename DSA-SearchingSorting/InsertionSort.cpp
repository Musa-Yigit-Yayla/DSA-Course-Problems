#include <iostream>

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
};

