#include <iostream>
#include <vector>
#include "MatrixMultiplication.cpp"
#include "GeeksIslandProblem.cpp"
#include "SpiralMatrixTraversal.cpp"
#include "MedianOfMatrix.cpp"

using namespace std;
int main(){

    /*Solution sol;
    vector<vector<int>> a;
    vector<vector<int>> b;

    int aRowSize , aColumnSize;
    int bRowSize, bColumnSize;

    cout << "Enter A's dimensions respectively: ";
    cin >> aRowSize >> aColumnSize;
    cout << "\nEnter B's dimensions respectively: ";
    cin >> bRowSize; bColumnSize;

    cout << "\nEnter elements of A:";
    for(int i = 0; i < aRowSize; i++){
        vector<int> currRow;
        for(int j = 0; j < aColumnSize; j++){
            int value;
            cin >> value;
            currRow.push_back(value);
        }
        a.push_back(currRow);
        cout << "\n";
    }
    cout << "\nEnter elements of B:";
    for(int i = 0; i < aRowSize; i++){
        vector<int> currRow;
        for(int j = 0; j < aColumnSize; j++){
            int value;
            cin >> value;
            currRow.push_back(value);
        }
        b.push_back(currRow);
        cout << "\n";
    }
    cout << "Connor" << endl;
    vector<vector<int>> result = sol.multiplyMatrix(a, b);
    cout << "Mcgregor";
    sol.printMatrix(result);
    */

    vector<vector<int>> vec = {{6, 6, 2, 28, 2},{12, 26, 3, 28, 7},{22, 25, 3, 4, 23}};
    //GeeksIslandProblem gip;
    //cout << gip.water_flow(vec, 5, 5) << endl
    //SpiralMatrixTraversal smt;
    //smt.spirallyTraverse(vec, 3, 5);
    MedianOfMatrix* mom = new MedianOfMatrix();
    int median = mom->getMedian(vec, 3, 5);
    cout << "Median of the matrix is " << median << endl;
    delete mom;
    return 0;
}
