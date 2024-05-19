#include <iostream>

using namespace std;

class MatrixDestinationDP{
public:
    bool checkVisitible(bool** dp, int i, int j){
        bool result = false;
        if(i == 0 && j == 0){
            return true;
        }
        else if(i == 0){
            //we can only check left
            result = dp[i][j - 1];
        }
        else if(j == 0){
            result = dp[i - 1][j];
        }
        else{
            result = dp[i][j - 1] || dp[i - 1][j];
        }
        return result;
    }

    bool canReach(int mat[R][C], int n, int i, int j)
    {
       //we can use a tabulated bottom up dp approach to solve the problem
       //we will have a 2d bool array with exact same size with the input matrix
       //each cell in the 2d dp table will represent whether a cell is reachable

       if(n == 1){
           return true;
       }
       bool result = false;

       bool** dp = new bool*[n];
       for(int i = 0; i < n; i++){
           dp[i] = new bool[n];
           for(int j = 0; j < n; j++){
               dp[i][j] = false;
           }
       }
       //we can have 0,0 as false doesn't matter actually
       //set left and bottom cells from start to true if they are even
       dp[0][1] = mat[0][1] % 2 == 0;
       dp[1][0] = mat[1][0] % 2 == 0;

       if(dp[0][1] || dp[1][0]){ //initial entry ok
           for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++){
                   if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0)){
                       continue;
                   }
                   dp[i][j] = mat[i][j] % 2 == 0 && checkVisitible(dp, i, j);
               }
           }
           result = dp[n - 1][n - 1];
       }
       /*for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
               cout << dp[i][j] << " ";
           }
           cout << endl;
       }*/
       for(int i = 0; i < n; i++){
           delete[] dp[i];
       }
       delete[] dp;

       return result;

    }
};


