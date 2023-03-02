#include <iostream>
#include <vector>
#include "QuadraticProbing.cpp"
#include "HashingForPair.cpp"

using namespace std;

int main()
{
    QuadraticProbing qp;
    vector<int> hashVector;
    int arr[] = {21, 10, 32, 43};
    int arrLength = 4;
    qp.QuadraticProbe(hashVector, 11, arr, arrLength);

    int arr1[7] = {61, 14, 75, 71, 36, 34, 12};
    HashingForPair hfp;
    cout << hfp.sumExists(arr, 7, 68);
    return 0;
}
