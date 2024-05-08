#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Player{
public:
    Player(string name, int price, int score): name{name}, price{price}, score{score} {}
    string name;
    int price;
    int score;
};

class PlayerSelect{
public:
    int select1(vector<Player>& players, int maxCredits){
        int n = players.size();
        int dp[n + 1][maxCredits + 1];

        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i < maxCredits + 1; i++){
            dp[0][i] = 0;
        }
        //proceed with 01 knapsack loop body
        for(int i = 1; i < n + 1; i++){
            Player currPlayer = players.at(i - 1);
            for(int j = 1; j < maxCredits + 1; j++){

                if(currPlayer.price <= j){ //check the weight property's satisfaction
                    dp[i][j] = max(currPlayer.score + dp[i - 1][j - currPlayer.price], dp[i - 1][j]);
                }
                else{
                    //we cannot incorporate this player hence just propagate the previous optimal solution
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        //result is always at the latest cell
        return dp[n][maxCredits];
    }
    int select2(vector<Player>& players, int maxPlayers){


    }

    void printTest(){
        vector<Player> players = {
            {"Tony Parker", 15, 120},
            {"Manu Ginobili", 10, 90},
            {"Rajon Rondo", 10, 55},
            {"Kobe Bryant", 20, 220},
            {"Damian Lillard", 10, 60},
            {"Tim Duncan", 25, 250},
            {"David Robinson", 20, 120},
            {"Lebron James", 27, 300},
            {"Charles Barkley", 15, 150},
            {"Kevin Garnett", 10, 80},
            {"Joakim Noah", 3, 20}
        };
        cout << "Select1: " << this->select1(players, 100) << endl;
    }

};
