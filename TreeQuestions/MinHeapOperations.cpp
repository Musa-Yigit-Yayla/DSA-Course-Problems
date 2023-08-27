#include <iostream>
#include <cstddef>

using namespace std;
//The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};

//Function to extract minimum value in heap and then to store
//next minimum value at first index.
void printArr(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}
int MinHeap::extractMin()
{
    // Your code here
    int returnValue = -1;
    if(this->heap_size != 0){
        returnValue = this->harr[0];
        this->deleteKey(0);
    }
    //cout << "After extracting " << returnValue << endl;
    //printArr(this->harr, this->heap_size);
    return returnValue;
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    // Your code here
    //delete the last leaf on the heap then we can
    if(this->heap_size != 0){
        if(i == this->heap_size - 1){
            //simply delete the last node and move on
            this->harr[i] = 0;
        }
        else{
            //retrieve the last node
            int lastValue = this->harr[this->heap_size - 1];
            this->harr[this->heap_size - 1] = 0;
            //assign the last value to the given index which is originally supposed to be deleted
            this->harr[i] = lastValue;
            //trickle down the newly updated value if appropriate
            int smallerIndex = -1;
            int smallerValue = INT_MAX;
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            int leftChild = INT_MAX;
            int rightChild = INT_MAX;

            if(leftIndex  < this->heap_size)
                leftChild = this->harr[leftIndex];
            if(rightIndex < this->heap_size)
                rightChild = this->harr[rightIndex];

            if(leftChild < rightChild){
                smallerIndex = leftIndex;
                smallerValue = this->harr[leftIndex];
            }
            else if(rightChild != INT_MAX){
                smallerIndex = rightIndex;
                smallerValue = this->harr[rightIndex];
            }
            int newIndex = i;
            while(smallerValue < lastValue){
                //this while block satisfies the condition in which there is at least one smaller child
                //hence we must trickle down
                //update the conditions so as to keep trickling down the element
                newIndex = smallerIndex;
                leftIndex = 2 * newIndex + 1;
                rightIndex = 2 * newIndex + 2;

                int temp = this->harr[smallerIndex];
                this->harr[smallerIndex] = lastValue;
                this->harr[newIndex] = temp;


                leftChild = INT_MAX;
                rightChild = INT_MAX;

                if(leftIndex  < this->heap_size)
                    leftChild = this->harr[leftIndex];
                if(rightIndex < this->heap_size)
                    rightChild = this->harr[rightIndex];

                if(leftChild < rightChild){
                    smallerIndex = leftIndex;
                    smallerValue = this->harr[leftIndex];
                }
                else if(rightChild != INT_MAX){
                    smallerIndex = rightIndex;
                    smallerValue = this->harr[rightIndex];
                }
                else{
                    smallerValue = INT_MAX; //this will ultimately break the loop and avoid infinite
                    //iteration
                }
            }
        }
        //decrement the heap size by 1
        if(this->heap_size > 0){
            this->heap_size--;
        }
        //cout << "After deleting the " << to_string(i) << "th element" << endl;
        //printArr(this->harr, this->heap_size);
    }
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k)
{
    // Your code here
    //heap size can be 0 at minimum which indicates that the heap is empty
    //insert at the last position and trickle up if necessary until the right position is found
    if(this->heap_size < this->capacity){
        if(this->heap_size == 0){
            //add the root element
            this->harr[0] = k;
        }
        else{
            //add as the latest element
            this->harr[this->heap_size] = k;
            //retrieve the parent
            int currIndex = this->heap_size;
            int parentIndex = (currIndex - 1) / 2;
            while(parentIndex >= 0 && this->harr[parentIndex] > k){
                //swap the current indexed element with its parent
                int temp = this->harr[parentIndex];
                this->harr[parentIndex] = this->harr[currIndex];
                this->harr[currIndex] = temp;

                //update the parent and curr indexes
                currIndex = parentIndex;
                parentIndex = (currIndex - 1) / 2;
            }
        }
        this->heap_size++;
        //cout << "After inserting the " << k << endl;
        //printArr(this->harr, this->heap_size);
    }

}
//2* i + 1, 2* i + 2 for child nodes
//(i - 1) / 2 for parent node
//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
