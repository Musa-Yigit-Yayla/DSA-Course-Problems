#include <vector>
#include <iostream>

using namespace std;

class SpiralMatrixTraversal{
public:
    //Function to print the list of integers denoting spiral traversal of matrix
    //r denotes row count, c denotes column count
    void spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
        int left = 0, top = 0, bottom = r - 1, right = c - 1;

        while(left <= right && bottom >= top){
            //print top row
            vector<int> currRow = matrix.at(top);
            for(int i = left; i <= right; i++){
                cout << currRow[i] << " "; //out of bounds
            }
            top++;
            //print right column
            for(int j = top; j <= bottom; j++){
                cout << matrix[j][right] << " ";
            }
            right--;
            //print bottom row in reverse order
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    if(left != bottom || top != right)
                    cout << matrix[bottom][i] << " "; // last print is done here
                }
                bottom--;
            }
            if(left <= right){
                //print left column from bottom to top (top inclusive)
                for(int i = bottom; i >= top; i--){
                    cout << matrix[i][left] << " ";
                }
                left++;
            }
        }
    }
};
