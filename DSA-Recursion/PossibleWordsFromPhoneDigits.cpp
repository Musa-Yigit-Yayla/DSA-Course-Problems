#include <bits/stdc++.h>
#include <vector>
#include <string>
#include "Permutation.cpp"

using namespace std;

class PossibleWordsFromPhoneDigits{
private:
    string arr[10][] = {{"1", "1"},
                        {"2", "ABC"},
                        {"3", "DEF"},
                        {"4", "GHI"},
                        {"5", "JKL"},
                        {"6", "MNO"},
                        {"7", "PQRS"},
                        {"8", "TUV"},
                        {"9", "WXYZ"},
                        {"0", "0"},}
public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N){
        //Your code here
        string digitsPressed = "";
        for(int i = 0; i < N; i++){
            digitsPressed += a[i];
        }

    }


};
