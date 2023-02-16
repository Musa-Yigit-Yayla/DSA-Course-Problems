#include <vector>

using namespacestd;

class BoundaryTraversal{
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m){
        // code here
        vector<int> result;
        if(n == 1){
		    for(int i = 0; i < m; i++)
			    result.push_back(matrix[0][i]);
	    }
	    else if(1 == m)
	    {
	    	for(int i = 0; i < n; i++)
	    		result.push_back(matrix[i][0]);
    	}
        int i, j;

        for(i = 0, j = 0; i < matrix.size(); i++){
            result.push_back(matrix[0][i]);
        }
        i = 1;
        while(i < n){
            j++;
            result.push_back(matrix[i][m - 1]);

        }
        i = n - 2;
        while(i >= 0){

            result.push_back(matrix[m - 1][i]);
            i--;
        }
        while(i >= 1){

            result.push_back(matrix[i][0]);
            i--;
        }
        result.pop_back();
        return result;
    }
};
