#include <algorithm>

using namespace std;

class Knapsack01{
public:
    int knapSack(int W, int wt[], int val[], int n) {
       //dp table will have row indexes as element indexes, and column indexes up to max weight W
       int dp[n + 1][W + 1];
       for(int i = 0; i < n + 1; i++){
           dp[i][0] = 0;
       }
       for(int i = 0; i < W + 1; i++){
           dp[0][i] = 0;
       }
       //traverse in row major fashion
       for(int i = 1; i < n + 1; i++){
           for(int j = i; j < W + 1; j++){ //j represents curr available weight
               int currWeight = wt[i - 1];
               if(currWeight <= j){
                   dp[i][j] = max(currWeight + dp[i - 1][j - currWeight], dp[i - 1][j]);
               }
               else{
                   //we cannot take the current weight retrieve the top neighbor element this time
                   dp[i][j] = dp[i - 1][j];
               }
           }
       }
       return dp[n][W];
    }
};
