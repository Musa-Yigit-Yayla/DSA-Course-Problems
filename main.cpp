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

    int a[7]{7, 10, 4, 10, 6, 5, 2};
    //cout << MaximumIndex::secondMaxIndex(a, 6) << endl;
    //MaximumIndex::getDistinctElements(a, 6);
    //MaximumIndex::moveZerosToEnd(a, 8);
    //MaximumIndex::printArray(a, 8);
    MaximumIndex::getLeaders(a, 7);
    return 0;
}
