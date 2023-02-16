#include <vector>

using namespacestd;

class BoundaryTraversal{
    public:
    //Function to return list of integers that form the boundary
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m)
    {
        // code here
        int i, j;
        vector<int> result;
        for(i = 0, j = 0; i < matrix.size(); i++){
            result.push_back(matrix[j][i]);
        }
        i--;
        while(j < matrix.at(0).size() - 1){
            j++;
            result.push_back(matrix[j][i]);

        }

        while(i > 0){
            i--;
            result.push_back(matrix[j][i]);

        }
        while(j > 0){
            j--;
            result.push_back(matrix[j][i]);

        }
        result.pop_back();
        return result;
    }
};
