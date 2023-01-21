#include <iostream>

using namespace std;

class Matchsticks{
public:
    void printGame(){
        cout << matchGame(0);

    }
    int matchGame(long long N) {

        cin >> N;
        // code here
        int maxNoOfMatchSticksToPick = 4;
        if(N % (maxNoOfMatchSticksToPick + 1) == 0){
            return - 1;
        }
        //find x such that N - X mod 5 is 0
        int o2 = 1, o3 = 2, o4 = 3, o5 = 4;
        if((N - o2) % (maxNoOfMatchSticksToPick + 1) == 0){
            return o2;
        }
        else if((N - o3) % (maxNoOfMatchSticksToPick + 1) == 0){
            return o3;
        }
        if((N - o4) % (maxNoOfMatchSticksToPick + 1) == 0){
            return o4;
        }
        if((N - o5) % (maxNoOfMatchSticksToPick + 1) == 0){
            return o5;
        }
    }
};
