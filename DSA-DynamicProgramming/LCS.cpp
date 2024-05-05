#include <string>
#include <cmath>

using namespace std;

class LCS{
public:
    int lcs(int n, int m, string s1, string s2){
        // your code here
        int** dp = new int*[n + 1];
        for(int i = 0; i < n + 1; i++){
            dp[i] = new int[m + 1];
            dp[i][0] = 0;
        }
        for(int i = 0; i < m + 1; i++){
            dp[0][i] = 0;
        }
        //dp table cells represent the length of the longest common subsequence for two chars
        //index 1, 1 represents s1.at(0), s2.at(0) in some sense

        //traverse from left to right each row
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                char ch1 = s1.at(i - 1);
                char ch2 = s2.at(j - 1);
                if(ch1 == ch2){
                    //retrieve the top left diagonal lcs result and assign + 1 to that result into this cell
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int result = dp[n][m]; //always return the latest index cell as it contains the max length
        for(int i = 0; i < n + 1; i++){
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }
};
