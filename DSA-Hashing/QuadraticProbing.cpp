#include <cmath>
#include <vector>

using namespace std;

class QuadraticProbing{
  public:
    //Function to fill the array elements into a hash table
    //using Quadratic Probing to handle collisions.
    void QuadraticProbe(vector<int>& hashVector, int hashSize, int arr[], int N){
        //Your code here
        //set the each value of hash into int min
        for(int i = 0; i < hashSize; i++){
            hashVector.push_back(-1);
        }
        for(int i = 0; i < N; i++){
            int curr = arr[i];
            int hashIndex = (curr % hashSize);

            if(hashVector.at(hashIndex) == -1){
                //insert
                hashVector.erase(hashVector.begin() + hashIndex);
                hashVector.insert(hashVector.begin() + hashIndex, curr);
            }
            else{
                //use the quadratic probing
                int l = 1;
                int hashLength = hashSize;
                while(hashIndex < hashLength && hashVector.at(hashIndex) != -1){
                    hashIndex = ((curr % hashSize) + (static_cast<int>(pow(l, 2)))) % hashLength;
                    if(hashVector.at(hashIndex) == -1){
                        hashVector.erase(hashVector.begin() + hashIndex);
                        hashVector.insert(hashVector.begin() + hashIndex, curr);
                        break;
                    }
                    l++;
                }
            }
        }
    }
};

