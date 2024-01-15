#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getSmallerOnRight(int* arr, int n);
int subArrHelper(int* arr, int n);

int main() {

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int n;
        cin >> n;

        int* arr = new int[n];
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        cout << getSmallerOnRight(arr, n) << endl;
        delete[] arr;
    }
	return 0;
}

int subArrHelper(int* arr, int n){
    return 0;
}
int getSmallerOnRight(int* arr, int n){
    int result = 0;
    for(int i = 0; i < n - 1; i++){
        vector<int> checkedList;
        int currRoot = arr[i];
        int currResult = 0;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < currRoot && count(checkedList.begin(), checkedList.end(), arr[j]) == 0){
                checkedList.push_back(arr[j]);
                currResult++;
            }
        }
        if(currResult > result){
            result = currResult;
        }
    }
    return result;
}
