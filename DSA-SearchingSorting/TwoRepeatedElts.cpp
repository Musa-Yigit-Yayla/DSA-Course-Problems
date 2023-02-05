#include <iostream>
#include <vector>

using namespace std;

class TwoRepeatedElts{
public:
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        vector<int> returnValue;
        int firstEltOccurence = 0;
        int firstElt = arr[0];
        for(int i = 0; i < N + 2; i++){
            if(firstElt == arr[i]){
                firstEltOccurence++;
            }
            if(arr[arr[i]] < 0 || (arr[i] == arr[arr[i]] && count(returnValue.begin(), returnValue.end(), firstElt) == 0)){
                returnValue.push_back(arr[i]);
            }
            else if(firstEltOccurence > 1 && count(returnValue.begin(), returnValue.end(), firstElt) == 0){
                returnValue.push_back(firstElt);
            }
            arr[i] *= -1;
        }
        return returnValue;
    }
};
