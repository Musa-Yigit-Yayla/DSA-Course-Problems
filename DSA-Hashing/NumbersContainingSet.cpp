/*
*GFG problem to display the numbers from 1 to 1000000 which contain a set of digits only.
*Implemented by Musa Yiğit Yayla
*/
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;

class NumbersContainingSet{
    const int n = 3;
    int* arr;
    unordered_set<int> numberSet(arr, arr + n);
    unordered_map<int, int> numberMap;

    //Function to find all the numbers with only 1,2 and 3 in their digits.
    void findAll(){
        //code here
        this->arr = new int[n];
        for(int i = 0; i < n; i++){
            this->arr[i] = i + 1;
        }
        for(int i = 0; i < n; i++){
            this->helper(arr[i]);
        }
        for(auto it: numberSet){
            this->numberMap.at(it) = 1;
        }
        delete[] arr;
    }
    void helper(int x){
        if(x < pow(10, 6)){
            for(int i = 0; i < n; i++){
                int curr = this->arr[i];
                this->helper(x * 10 + curr);
            }
            this->numberSet.insert(x);
        }
    }
};
