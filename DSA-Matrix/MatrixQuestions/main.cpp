#include <iostream>
#include <vector>
#include "MatrixMultiplication.cpp"

int main(){

    Solution sol;
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

    return 0;
}
