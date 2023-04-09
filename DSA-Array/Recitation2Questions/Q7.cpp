//Split array function given in Recitation2
//Musa Yiğit Yayla
#include <iostream>

using namespace std;
class Q7{
public:
    //Assuming i1 and i2 are valid indexes ensuring a valid split of array
    //subArr1 will contain the middle elements whereas subArr2 will contain the rest
    //i2 inclusive, i2 > i1
    void splitArray(const int arr[], int n, int*& subArr1, int*& subArr2, int i1, int i2){
        delete[] subArr1; //you can delete even if it's a nullptr
        delete[] subArr2;

        subArr1 = new int[i2 - i1 + 1];
        subArr2 = new int[n - i2 + i1 - 1];
        for(int i = i1, counter = 0; i <= i2; i++, counter++){
            subArr1[counter] = arr[i];
        }
        for(int i = 0, counter = 0; i < n; i++, counter++){
            if(i >= i1 && i <= i2){
                counter--;
                continue;
            }
            subArr2[counter] = arr[i];
        }
    }

    void displayArr(const int* arr, int n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
