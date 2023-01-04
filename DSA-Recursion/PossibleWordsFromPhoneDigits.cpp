#include <bits/stdc++.h>
#include <vector>
#include <string>
#include "Permutation2.cpp"

using namespace std;

class PossibleWordsFromPhoneDigits{

public:

    PossibleWordsFromPhoneDigits(){
        string arr0[2] = {"1", "1"};
        this->arr[0] = arr0;

        string arr1[2] = {"2", "ABC"};
        this->arr[1] = {"2", "ABC"};

        string arr2[2] = {"3", "DEF"};
        this->arr[2] = {"3", "DEF"};

        string arr3[2] = {"4", "GHI"};
        this->arr[3] = {"4", "GHI"};

        string arr4[2] = {"5", "JKL"};
        this->arr[4] = {"5", "JKL"};

        string arr5[2] = {"6", "MNO"};
        this->arr[5] = {"6", "MNO"};

        string arr6[2] = {"7", "PQRS"};
        this->arr[6] = {"7", "PQRS"};

        string arr7[2] = {"8", "TUV"};
        this->arr[7] = {"8", "TUV"};

        string arr8[2] = {"9", "WXYZ"};
        this->arr[8] = {"9", "WXYZ"};

        string arr9[2] = {"0", "0"}
        this->arr[9] = {"0", "0"};
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N){
        //Your code here
        string digitsPressed = "";
        for(int i = 0; i < N; i++){
            digitsPressed += a[i];
        }
        //find all permutations of the digits
        perm->find_permutation(digitsPressed);
        vector<string> allPermutations = perm->getAllPermutations();

        for(size_t i = 0; i < allPermutations.size(); i++){
            string currStr = allPermutations.at(i);
            comb(currStr);
        }



        //sort the values
        sort(returnValue.begin(), returnValue.end());
        delete this->perm;
        return this->returnValue;
    }

    void comb(string originalString){
        comb('a', "", originalString.length(), 0, originalString);
    }
    /*
    * n is the length of originalString
    */
    void comb(const char& ch, string currString, const int& n, int index, string originalString){
        if(currString.length() == n){
            //base case, add the currString to the results
            this->returnValue.push_back(currString);
            return;
        }
        for(int i = index; i < n; i++){
            if(index != 0)
             comb(originalString.at(i), currString + ch, n, index + 1, originalString);
            else{
            comb(originalString.at(i), currString, n, index + 1, originalString);
            }
        }

    }
private:
    vector<string> returnValue;
    Permutation2* perm = new Permutation2();
    string arr[][10]; //= {{"1", "1"},{"2", "ABC"},{"3", "DEF"},{"4", "GHI"},{"5", "JKL"},{"6", "MNO"},{"7", "PQRS"},{"8", "TUV"},{"9", "WXYZ"},{"0", "0"}};
};
