#include <iostream>

using namespace std;

class ArrayOperations{
public:
    //Return int min if elt dne
    int delete1(int arr[], int n, int x){
        int i;

        for(i = 0; i < n; i++){
            if(arr[i] == x){
                break;
            }
        }
        if(i == n){
            return n; // elt dne
        }
        for(int j = i; j < n; j++){
            arr[j] = arr[j + 1];
        }
        return n - 1;
    }


};
