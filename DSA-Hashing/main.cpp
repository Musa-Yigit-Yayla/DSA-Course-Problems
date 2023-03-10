#include <iostream>
#include <vector>
#include "QuadraticProbing.cpp"
#include "HashingForPair.cpp"
#include "SortArrayAccordingToOther.cpp"
#include "FirstRepeatingElement.cpp"
#include "SubarrayWith0Sum.cpp"
#include "LongestConsequtiveSubsequence.cpp"


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
    SortArrayAccordingToOther saato;

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

    LongestConsequtiveSubsequence lcs;
    int arr[7] = {1, 3, 9, 2, 8, 2};
    cout << lcs.longestSubsequence(arr, 7);

    return 0;
}
