#include <cmath>
#include <vector>

using namespace std;

class QuadraticProbing{
  public:
    //Function to fill the array elements into a hash table
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector<int>& hashVector, int hashSize, int arr[], int N){
        //Your code here
        //set the each value of hash into int min
        for(int i = 0; i < hashSize; i++){
            hashVector.at(i) = -1;
        }
        for(int i = 0; i < N; i++){
            int curr = arr[i];
            int hashIndex = (hashSize % N);

            if(hashVector.at(hashIndex) == -1){
                //insert
                hashVector.insert(hashVector.begin() + hashIndex, curr);
            }
            else{
                //use the quadratic probing
                int l = 1;
                while(hashVector.at(hashIndex) != -1){
                    hashIndex = ((hashSize % N) + (static_cast<int>(pow(l, 2)))) % N;
                    if(hashVector.at(hashIndex) == -1){
                        hashVector.insert(hashVector.begin() + hashIndex, curr);
                    }
                    l++;
                }
            }
        }
    }

};

