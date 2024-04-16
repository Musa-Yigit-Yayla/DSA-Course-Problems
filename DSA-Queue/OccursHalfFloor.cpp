#include <cmath>

using namespace std;
class OccursHalfFloor{
    bool occursHalfFloor(int* A, int n){
        int maxElt = A[0];
        int minElt = A[0];
        //first we keep track of the positive elements to check if the condition ceil n/2 of any element has occured that times
        for(int i = 1; i < n; i++){
            if(A[i] > maxElt){
                maxElt = A[i];
            }
            else if(A[i] < minElt){
                minElt = A[i];
            }
        }
        int* B = new int[maxElt + 1];
        //initialize B to all zeros
        for(int i = 0; i < maxElt + 1; i++){
            B[i] = 0;
        }
        for(int i = 0; i < n; i++){
            int currElt = A[i];
            if(currElt >= 0){
                B[currElt]++;
            }
        }
        //check if we have any occurrence count satisfying the result
        for(int i = 0; i < n; i++){
            int currElt = A[i];
            if(currElt >= 0 && B[currElt] > ceil(n / 2)){
                return true;
            }
        }
        delete B;
        if(minElt < 0){
            //first reset B to all zeros
            B = new int[(minElt * - 1) + 1];
            for(int i = 0; i < (minElt * - 1) + 1; i++){
                B[i] = 0;
            }
            //now perform similar operation to negative entries in A
            for(int i = 0; i < n; i++){
                int currElt = A[i];
                if(currElt < 0){
                    int arrIndex = currElt * -1;
                    B[arrIndex]++;
                }
            }
            //check the occurence counts
            for(int i = 0; i < n; i++){
                int currElt = A[i];
                if(currElt < 0 && B[currElt * -1] > ceil(n / 2)){
                    return true;
                }
            }
        }
        return false;
    }
};
