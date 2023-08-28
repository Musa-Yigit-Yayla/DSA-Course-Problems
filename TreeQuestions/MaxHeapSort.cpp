#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

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
      /*cout << "Curr array at heapify function body is: ";
          for(int i = 0; i < n; i++){
            cout << arr[i] << ", ";
          }
          cout << endl;*/
      while(currIndex < n && largerIndex < n && arr[currIndex] < largerChild){
          //swap with the larger child then update the indexes
          int temp = arr[currIndex];
          arr[currIndex] = largerChild;
          arr[largerIndex] = temp;
          /*cout << "Curr array at heapify while loop is: ";
          for(int i = 0; i < n; i++){
            cout << arr[i] << ", ";
          }
          cout << endl;*/

          currIndex = largerIndex;
          bool isLeftVisited = false;
          if(2 * currIndex + 1 < n){
            largerIndex = 2 * currIndex + 1;
            largerChild = arr[largerIndex];
            isLeftVisited = true;
          }
          if(2 * currIndex + 2 < n && arr[2 * currIndex + 2] > largerChild){
            largerIndex = 2 * currIndex + 2;
            largerChild = arr[largerIndex];
          }
          else if(!isLeftVisited){
            break;
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
            this->insertKey(arr[i], this->currSize);
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
            //cout << "Popped max is " << currMax << endl;
            this->heapify(this->arr, i);
            arr[i] = currMax;
        }
    }
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    //!!! This function returns the total sum of the frequencies of the elements in the array which occur k times
    int kMostFrequent2(int arr[], int n, int k){
        	// Your code here
        	int result = 0;
        	int freqCount = 0;
            //MaxHeapSort mhs;
            this->heapSort(arr, n);


            int currFreqElt;
            int currFreq = 0;
            int prevFreq = -1;
            int prevFreqElt = -1;
            for(int i = 0; i < n; i++){
                currFreqElt = arr[i];
                if(currFreqElt != prevFreqElt){
                    if(currFreq == k){
                        freqCount++;
                    }
                    prevFreq = currFreq;
                    prevFreqElt = currFreqElt;
                    currFreq = 1;
                }
                else{
                    currFreq++;
                }
            }
            return freqCount * k;

    }
     //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    static int kMostFrequent(int arr[], int n, int k){
        	// Your code here
        	int result = 0;
        	int freqCount = 0;
            MaxHeapSort mhs;
            //build a max heap based on the frequencies
            vector<int> usedElts;
            vector<int> frequencies;

            for(int i = 0; i < n; i++){
                int curr = arr[i];
                if(std::count(usedElts.begin(), usedElts.end(), curr) == 0){
                    int currFreq = std::count(arr, arr + n, curr);
                    frequencies.push_back(currFreq);
                    usedElts.push_back(curr);
                }
            }
            //convert the frequencies to a int array then build a max heap out of it
            int freqLength = frequencies.size();
            int freqArr[freqLength];
            for(int i = 0; i < frequencies.size(); i++){
                freqArr[i] = frequencies.at(i);
            }

            mhs.buildHeap(freqArr, freqLength);
            for(int i = 0; i < k; i++){
                result += mhs.popMax();
                mhs.heapify(mhs.getArr(), mhs.getCurrSize());
            }

            return result;


    }
private: //private helper functions
    void insertKey(int key, int currSize){
        if(currSize < this->n){
            this->arr[currSize] = key;
            //since we use a max heap we must simply trickle the newly inserted element if applicable
            int index = currSize;
            int parentIndex = (index - 1) / 2;
            while(parentIndex >= 0 && this->arr[parentIndex] < this->arr[index]){
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
