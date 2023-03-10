#include "Matchsticks.cpp"
#include "MaximumIndex.cpp"
#include <iostream>
#include <vector>
#include "ArrayContest1.cpp"
#include "PatternChecker.cpp"
#include "MajorityElement.cpp"
#include "SmallestPositiveMissing.cpp"

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
    int d[18]{85, 62, 2, 88, 16, 31, 36, 12, 10, 7, 79, 4, 37, 27, 63, 1, 4, 87};
    int e[5]{1, 4, 20, 3, 10};
    int sum = 33;
    vector<int> f{2, 3, 2, 3, 5};
     int g[4]{7, 4, 0, 9};
    //cout << MaximumIndex::secondMaxIndex(a, 6) << endl;
    //MaximumIndex::getDistinctElements(a, 6);
    //MaximumIndex::moveZerosToEnd(a, 8);
    //MaximumIndex::printArray(a, 8);
    MaximumIndex::getLeaders(a, 7);
    //vector<vector<int>> vec = MaximumIndex::getFrequenciesFromSortedArray(b, 6);
    //MaximumIndex::print2DVector(vec);
    //cout << MaximumIndex::getMaxConsecutiveOnes(c, 9);
    //MaximumIndex mi;
    //cout << mi.maxIndexDiff(d, 18) << endl;
    //cout << mi.subarrayWithGivenSum(e, 5, sum);
    cout << endl;
    cout << MaximumIndex::trappingWater(g, 4) << endl;
    PatternChecker checker;
    vector<int> h = checker.pattern(16);
//    MajorityElement me;
  //  cout << me.majorityElement({3, 1, 3, 3, 2}, 5) << endl;

    int arr[15] = {37, 6, -7, 41, -23, 15, 9, -14, -18, 1, -13, -22, 25, -43, 24};
    SmallestPositiveMissing spm;
    //cout << spm.missingNumber(arr, 15);
    /*spm.partition(arr, 15);
    for(int i: arr){
        cout << i << " ";
    }*/
    spm.floorSqrt(6);
    return 0;
}
