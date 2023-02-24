#include <vector>

using namespace std;

//insert at the hashIndex pos//insert at the hashIndex pos
class LinearProbing{
public:
    //Function to fill the array elements into a hash table
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        vector<int> hashTable(hashSize);
        //Your code here
        for(int i = 0; i < hashSize; i++){
            hashTable.at(i) = -1;
        }
        //mod hash size will be used
        for(int i = 0; i < sizeOfArray; i++){
            int hashIndex = arr[i] % hashSize;
            int insertionValue = arr[i];
            int count = 1;
            while(hashTable.at(hashIndex) != -1){

                hashIndex = (arr[i] + count) % hashSize;
                count++;
            }
            //insert at the hashIndex pos
            hashTable.insert(hashTable.begin() + hashIndex, insertionValue);
        }
        return hashTable;

    }


};
