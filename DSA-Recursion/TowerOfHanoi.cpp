#include <iostream>

using namespace std;

class TowerOfHanoi{
public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux) { // A C B
        //base case
        if(n == 0){
            return this->answer;
        }


        toh(n - 1, from, to, aux);
        cout << "move disk " << n << " from rod " << from << " to rod " << aux << endl;
        this->answer++;
        toh(n - 1, from, aux, to);
    }
    private:
    long long answer = 0;

};
