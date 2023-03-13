#include <iostream>
#include <vector>
#include <unordered_map>
#include "QuadraticProbing.cpp"
#include "HashingForPair.cpp"
#include "SortArrayAccordingToOther.cpp"
#include "FirstRepeatingElement.cpp"
#include "SubarrayWith0Sum.cpp"
#include "LongestConsequtiveSubsequence.cpp"
#include "NumbersContainingSet.cpp"

using namespace std;

int main()
{
    /*QuadraticProbing qp;
    vector<int> hashVector;
    int arr[] = {21, 10, 32, 43};
    int arrLength = 4;
    qp.QuadraticProbe(hashVector, 11, arr, arrLength);

    int arr1[7] = {61, 14, 75, 71, 36, 34, 12};
    HashingForPair hfp;
    cout << hfp.sumExists(arr, 7, 68);
    */
    /*SortArrayAccordingToOther saato;

    vector<int> vec({2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8});
    vector<int> vec1({2, 1, 8, 3});
    vector<int> vec2({1, 2, 3, 4, 5});
    saato.sortA1ByA2(vec, 11, vec1, 4);

    for(int i: vec){
        cout << i << " ";
    }
    cout << endl;

    vector<long long int> vec3({0, 0, 5, 5, 0, 0});
    SubarrayWith0Sum* sw0s = new SubarrayWith0Sum();
    cout << sw0s->findSubarray(vec3, vec3.size()) << endl;
    delete sw0s;
    */
    LongestConsequtiveSubsequence lcs;
    int arr[7] = {1, 3, 9, 2, 8, 2};
    int arr2[7] = {2, 6, 1, 9, 4, 5, 3};
    int arr3[5] = {1, 2, 3, 4, 5};
    int arr4[20] =  {6, 6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4, 2, 1, 3, 4, 5, 9, 6};
    //cout << lcs.longestSubsequence(arr, 7);
    //cout << lcs.findLongestConseqSubseq(arr3, 5) << endl;
    //cout << lcs.findLongestConseqSubseq(arr2, 7) << endl;
    cout << lcs.findLongestConseqSubseq(arr4, 20) << endl;

    NumbersContainingSet ncs(arr, 7);
    ncs.findAll();

    int data = 3;
    const int* ptr = &data;
    const int* const ptr2 = &data;
    return 0;
}
