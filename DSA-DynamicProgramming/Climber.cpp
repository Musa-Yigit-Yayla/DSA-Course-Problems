 #include <climits>
 #include <cmath>
 #include <algorithm>


using namespace std;
class Climber{
public:
    //n x m grid
    int getSafestPath(int** grid, int n, int m){
        int dp[n * m];
        for(int i = 0; i < m; i++){ //initialize the first walls
            int lastRowIndex = (n - 1) * (m); //row begin
            dp[lastRowIndex + i] = grid[n - 1][i];
        }
        for(int i = 1; i < n; i++){
            int rowIndex = n - i - 1;
            int rowIndexBegin = (n - i - 1) * m; //row begin
            for(int j = 0; j < m; j++){
                int bottom = dp[(rowIndex + 1) * m + j];
                int bottomLeft = INT_MAX;
                int bottomRight = INT_MAX;
                if(j > 0){
                    bottomLeft = dp[(rowIndex + 1) * m + j - 1];
                }
                if(j < m - 1){
                    bottomRight = dp[(rowIndex + 1) * m + j + 1];
                }
                dp[rowIndexBegin + j] = grid[rowIndex][j] + min(bottom, min(bottomLeft, bottomRight));
            }
        }
        //perform linear search on the very first row elements stored in dp
        int result = dp[0];
        for(int i = 1; i < m; i++){
            int curr = dp[i];
            if(curr < result){
                result = curr;
            }
        }
        return result;
    }
};
