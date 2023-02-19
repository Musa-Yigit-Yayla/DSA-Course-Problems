#include <iostream>
#include <vector>

using namespace std;

class DeterminantOfMatrix{
public:
    //n represents rows
    int determinantOfMatrix(const vector<vector<int>>& matrix, int n){
        int sum = 0;

        if(n == 1){
            return matrix[0][0]; //base case
        }
        vector<vector<int>> temp(n);
        for(int i = 0; i < n; i++){
            temp.at(i) = vector<int>(n);
        }
        int sign = 1; // sign that will alternate later on

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int curr = matrix[i][j];
                getCofactor(matrix, temp, 0, i, n);
                sum += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);

                sign *= -1;
            }
        }
        return sum;
    }
    void getCofactor(const vector<vector<int>>& matrix, vector<vector<int>>& temp, int p, int q, int n){
        int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = matrix[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    }
};
