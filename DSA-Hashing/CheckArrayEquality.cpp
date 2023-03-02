#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

#define ll long

using namespace std;

class CheckArrayEquality{
public:
    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here

        unordered_map<ll, int> hash; // contains value and occurence count pairs

        //append the first array's elements to the hash
        for(int i = 0; i < N; i++){
            int curr = A.at(i);
            if(hash.find(curr) == hash.end()){
                hash.insert({curr, 1});
            }
            else{
                //increment the count by one
                auto it = hash.find(curr);
                it->second++;
            }
        }
        //Traverse the second array and decrement the counts by one
        for(int i = 0; i < N; i++){
            int curr = B.at(i);
            if(hash.find(curr) == hash.end()){
                return false;
            }
            else{
                auto it = hash.find(curr);
                it->second--;
            }
        }
        //traverse the unordered_map and check whether each key's second value equals 0
        for(auto i: hash){
            if(i.second != 0){
                return false;
            }
        }

        return true;
    }
    void quickSort(vector<long long>& arr){
        quickSortHelper(arr, 0, arr.size() - 1);
    }
private:
    void quickSortHelper(vector<long long>& arr, int low, int high){
        if(high - low == 1 || high - low <= 0){
            return; // base case
        }
        int partitionIndex = partition(arr, low, high);
        quickSortHelper(arr, low, partitionIndex - 1);
        quickSortHelper(arr, partitionIndex + 1, high);
    }
    //Returns the index of the high after having partitioned the given vector
    //Takes the pivot as begin
    int partition(vector<long long>& arr, int low, int high){
        int pivot = low;
        while(low <= high){
            //search for the first element bigger than pivot
            for(int i = pivot; i < high; i++){
                if(arr.at(i) > pivot){
                    low = i;
                    break;
                }
            }
            for(int j = high; j >= low; j--){
                if(arr.at(j) < pivot){
                    high = j;
                    break;
                }
            }
            //swap the begin and end indexed elements
            long long temp = arr.at(low);
            arr.at(low) = arr.at(high);
            arr.at(high) = temp;
        }
        //swap the pivot with end
        long long temp = arr.at(pivot);
        arr.at(pivot) = arr.at(high);
        arr.at(low) = temp;

        return high;
    }
};
