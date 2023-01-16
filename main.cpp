#include "Matchsticks.cpp"
#include "MaximumIndex.cpp"
#include <iostream>
#include <vector>
using namespace std;

void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here

        vector<long long>::iterator it = arr.begin();

}

int main(){

    Matchsticks msticks;
    msticks.printGame();

    int a[8]{1,5,0,0, 8, 0, 9, 0};
    //cout << MaximumIndex::secondMaxIndex(a, 6) << endl;
    //MaximumIndex::getDistinctElements(a, 6);
    MaximumIndex::moveZerosToEnd(a, 8);
    MaximumIndex::printArray(a, 8);
    return 0;
}
