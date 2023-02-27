#include <cmath>

class QuadraticProbing{
  public:
    //Function to fill the array elements into a hash table
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector<int>& hash, int hashSize, int arr[], int N)
    {
        //Your code here
        //set the each value of hash into int min
        for(int i = 0; i < hashSize; i++){
            hash.at(i) = -1;
        }
        for(int i = 0; i < N; i++){
            int curr = arr[i];
            int hashIndex = (hashSize % N);

            if(hash.at(hashIndex) == -1){
                //insert
                hash.insert(hash.begin() + hashIndex, curr);
            }
            else{
                //use the quadratic probing
                int l = 1;
                while(hash.at(hashIndex) == -1){
                    hashIndex = ((hashSize % N) + (static_cast<int>(pow(l, 2)))) % N;
                    if(hash.at(hashIndex) == -1){
                        hash.insert(hash.begin() + hashIndex, curr);
                    }
                    l++;
                }
            }
        }
    }


};

