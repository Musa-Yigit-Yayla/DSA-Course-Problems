#include <string>
#include <cmath>

using namespace std;
//Longest palindromic subsequence of a string
class LPS{
public:

    int getLPS(string s){
        //use dp approach
        int n = s.size();
        int** dp = new int*[n]; //rows as start index, and column indices as end index

        for(int i = 0; i < n; i++){
            dp[i] = new int[n + 1];
            dp[i][i] = 0; //0 length chars
        }
        //start inclusive end exclusive
        for(int i = 0; i < n; i++){
            dp[i][i + 1] = 1; //single length chars
        }
        //we traverse diagonally, like the second diagonal right to bottom
        for(int endIndex = 2; endIndex <= n; endIndex++){
            for(int start = 0; start + endIndex <= n; start++){
                //we should calculate dp[start][start + endIndex]
                if(s.at(start) == s.at(start + endIndex - 1)){
                    dp[start][start + endIndex] = 2 + dp[start + 1][endIndex - 1];
                }
                else{
                    dp[start][start + endIndex] = max(dp[start][endIndex - 1], dp[start + 1][endIndex]);
                }
            }
        }
        return dp[0][n];
    }

};
