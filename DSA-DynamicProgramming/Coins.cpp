#include <cstddef>
#include <cmath>

using namespace std;

class Coins{
private:
    long long* dp = nullptr;

public:
    //Function to find the minimum number of coins to make the change
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value){
        long long result = recHelper(coins, numberOfCoins, value);
        if(result == INT_MAX){
            result = -1;
        }
        return result;
    }
    long long recHelper(int coins[], int numberOfCoins, int value){
        if(dp != NULL){
            delete[] dp;
        }
        dp = new long long[value + 1];
        for(int i = 0; i < value + 1; i++){
            dp[i] = INT_MAX;
        }
        if(numberOfCoins == 1){ // base case
            if(coins[0] == value){
                dp[0] = 1;
            }
            return dp[0];
        }
        else{

            int curr = coins[numberOfCoins];
            if(dp[numberOfCoins - 1] + curr == value){
                //update the dp table accordingly
                dp[numberOfCoins] = dp[numberOfCoins - 1] + 1;
            }
            return min(1 + recHelper(coins, numberOfCoins - 1, value - curr),
                        recHelper(coins, numberOfCoins - 1, value));
        }

    }

};
