#include <iostream>
#include <cstddef>

using namespace std;

#include <cstddef>

class MaxHeapSort{
private:
    int* arr = nullptr;
    int currSize = 0;
    int n;

public:
    //Heapify function to maintain heap property.
    //This function processes the given array pointer hence you can use it for other arrays too
    void heapify(int arr[], int n)
    {
      // Your Code Here
      //We should call the heapify when we have a semi-heap
      //trickle the first node down by swapping it with its larger child and continue the process
      int currIndex = 0;
      int largerChild = INT_MIN;
      int largerIndex = -1;
      if(2 * currIndex + 1 < n){
          largerIndex = 2 * currIndex + 1;
          largerChild = arr[largerIndex];
      }
      if(2 * currIndex + 2 < n && arr[2 * currIndex + 2] > largerChild){
          largerIndex = 2 * currIndex + 2;
          largerChild = arr[largerIndex];
      }
      while(currIndex < n && arr[currIndex] < largerChild){
          //swap with the larger child then update the indexes
          int temp = arr[currIndex];
          arr[currIndex] = largerChild;
          arr[largerIndex] = temp;

          currIndex = largerIndex;
          if(2 * currIndex + 1 < n){
            largerIndex = 2 * currIndex + 1;
            largerChild = arr[largerIndex];
          }
          if (2 * currIndex + 2 < n && arr[2 * currIndex + 2] > arr[largerIndex]) {
                largerIndex = 2 * currIndex + 2;
                largerChild = arr[2 * currIndex + 2];
        }
      }
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
            this->currSize++;
        }
    }


    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        this->buildHeap(arr, n);
        /*for(int i = 0; i < this->n; i++){
            cout << this->arr[i] << ", ";
        }
        cout << endl;*/

        for(int i = n - 1; i >= 0; i--){
            int currMax = this->popMax();
            this->heapify(this->arr, i);
            arr[i] = currMax;
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
    //Pops and returns the max element, once it's popped we will have a semi heap remaining
    int popMax(){
        int returnValue = -1;
        if(this->currSize != 0){
            returnValue = this->arr[0];
            if(this->currSize > 1){
                int lastElt = this->arr[this->currSize - 1];
                this->arr[0] = lastElt;
                this->arr[this->currSize - 1] = 0;
            }
            else{
                this->arr[this->currSize - 1] = 0;
            }
            this->currSize--;
        }
        return returnValue;
    }

};
