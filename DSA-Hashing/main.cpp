#include <iostream>
#include <vector>
#include "QuadraticProbing.cpp"

using namespace std;

int main()
{
    QuadraticProbing qp;
    vector<int> hashVector;
    int arr[] = {21, 10, 32, 43};
    int arrLength = 4;
    qp.QuadraticProbe(hashVector, 11, arr, arrLength);

    return 0;
}
