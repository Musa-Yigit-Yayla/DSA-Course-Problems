#include <iostream>
#include <vector>

using namespace std;
class MatrixMultiplication{
    public:
    //Function to multiply two matrices.
    vector<vector<int>> multiplyMatrix( const vector<vector<int>>& A, const vector<vector<int>>& B){
        // code here

        vector<vector<int>> result;


        int noOfColumnsInA = A.at(0).size();
        int noOfRowsInB = B.size();

        if(noOfColumnsInA == noOfRowsInB){
            for(int i = 0; i < A.size(); i++){
                vector<int> currRow;
                for(int j = 0; j < B.at(0).size(); j++){
                    currRow.push_back(calculateElt(A, B, i, j));
                }
                result.push_back(currRow);
            }
        }
        return result;
    }

    //Utility function to calculate an individual element on the matrix
    int calculateElt(const vector<vector<int>>& A, const vector<vector<int>>& B, int i, int j){
        int sum = 0;
        for(int k = 0; k < A.size(); k++){
            sum += (A.at(i).at(k) * B.at(k).at(j));
        }
        return sum;
    }
    //Utility function to print any given matrix of integers
    void printMatrix(const vector<vector<int>>& a){
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a.at(i).size(); j++){
                cout << a.at(i).at(j) << " ";
            }
            cout << endl;
        }
    }
};


