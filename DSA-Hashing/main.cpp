#include <iostream>
#include <vector>
#include "QuadraticProbing.cpp"
#include "HashingForPair.cpp"
#include "SortArrayAccordingToOther.cpp"

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
    int arr2[11] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int arr3[4] = {2, 1, 8, 3};
    vector<int> vec(arr2);
    vector<int> vec1(arr3);
    saato.sortA1ByA2(arr2, 11, arr3, 4);
    return 0;
}
