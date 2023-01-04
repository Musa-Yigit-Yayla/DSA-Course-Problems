#include <bits/stdc++.h>
#include <vector>
#include <string>
#include "Permutation2.cpp"

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
                        {"0", "0"},};
    vector<string> returnValue;-
    Permutation* perm = new Permutation();
public:
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




        delete this->perm;
        return this->returnValue;
    }

    void comb(string originalString){
        comb('', "", originalString.length(), 0, originalString);
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
            comb(originalString.at(i), currString + ch, n, index + 1, originalString);
        }

    }


};
