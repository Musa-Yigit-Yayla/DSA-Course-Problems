#include <iostream>
#include <cstddef>

using namespace std;

#include <cstddef>

class MaxHeapSort{
private:
    int* arr = nullptr;
    int n;

public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
      // Your Code Here
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Your Code Here
        if(this->arr != NULL){
            //deallocate the previous array
            delete[] this->arr;
        }
        this->arr = new int[n];
        this->n = n;
        for(int i = 0; i < this->n; i++){
            this->insertKey(arr[i], i);
        }
    }


    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        this->buildHeap(arr, n);

        for(int i = n - 1; i >= 0; i--){
            int currMax =
        }

    }
private: //private helper functions
    void insertKey(int key, int currSize){
        if(currSize < this->n){
            this->arr[currSize] = key;
            //since we use a max heap we must simply trickle the newly inserted element if applicable
            int index = currSize;
            int parentIndex = (index - 1) / 2;
            while(parentIndex >= 0 && this->arr[parentIndex] > this->arr[index]){
                //swap then update the indexes accordingly
                int temp = this->arr[index];
                this->arr[index] = this->arr[parentIndex];
                this->arr[parentIndex] = temp;

                index = parentIndex;
                parentIndex = (index - 1) / 2;
            }
        }
    }
    int popMax(){

    }

};
