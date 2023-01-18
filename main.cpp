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

    int a[7]{63, 70, 80, 33, 33, 47, 20};
    int b[6]{10, 10, 10, 25, 30, 30};
    bool c[9]{1,0,1,1,1,1, 0, 0,1};
    int d[15]{65, 6, 74, 94, 56, 89, 9, 63, 75, 25, 34, 68, 93, 48, 16};
    //cout << MaximumIndex::secondMaxIndex(a, 6) << endl;
    //MaximumIndex::getDistinctElements(a, 6);
    //MaximumIndex::moveZerosToEnd(a, 8);
    //MaximumIndex::printArray(a, 8);
    /*MaximumIndex::getLeaders(a, 7);
    vector<vector<int>> vec = MaximumIndex::getFrequenciesFromSortedArray(b, 6);
    MaximumIndex::print2DVector(vec);*/
    //cout << MaximumIndex::getMaxConsecutiveOnes(c, 9);
    MaximumIndex mi;
    cout << mi.maxIndexDiff(d, 15);
    return 0;
}
