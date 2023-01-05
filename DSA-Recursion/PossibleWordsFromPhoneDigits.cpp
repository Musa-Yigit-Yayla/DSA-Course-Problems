#include <bits/stdc++.h>
#include <vector>
#include <string>
#include "Permutation2.cpp"

using namespace std;

class PossibleWordsFromPhoneDigits{

public:

    PossibleWordsFromPhoneDigits(){
        vector<string> arr0{"1", "1"};
        this->arr.push_back(arr0);

        vector<string> arr1{"2", "ABC"};
        this->arr.push_back(arr1);

        vector<string> arr2{"3", "DEF"};
        this->arr.push_back(arr2);

        vector<string> arr3{"4", "GHI"};
        this->arr.push_back(arr3);

        vector<string> arr4{"5", "JKL"};
        this->arr.push_back(arr4);

        vector<string> arr5{"6", "MNO"};
        this->arr.push_back(arr5);

        vector<string> arr6{"7", "PQRS"};
        this->arr.push_back(arr6);

        vector<string> arr7{"8", "TUV"};
        this->arr.push_back(arr7);

        vector<string> arr8{"9", "WXYZ"};
        this->arr.push_back(arr8);

        vector<string> arr9{"0", "0"};
        this->arr.push_back(arr9);


    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N){
        //Your code here
        string digitsPressed = "";
        for(int i = 0; i < N; i++){
            digitsPressed += to_string(a[i]);
        }
        //find all permutations of the digits
        vector<string> allPermutations = perm->find_permutation(digitsPressed);


        for(size_t i = 0; i < allPermutations.size(); i++){
            string currStr = allPermutations.at(i);
            vector<string> words;
            //cout << currStr << " ";
            for(size_t j = 0; j < currStr.length(); j++){
                string currDigitIndex = "";
                currDigitIndex += currStr.at(j);

                int currDigit = stoi(currDigitIndex); // might be problematic
                string wordArray = (arr.at(currDigit - 1)).at(1); // now you have the string "ABC" for example. The values one digit can represent as a char.
                cout << wordArray << " ";
                //for(int k = 0; k < wordArray.size(); k++){

                //}
            }

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
        if(index == n){
            //base case, add the currString to the results
            cout << currString << " ";
            this->returnValue.push_back(currString);
            return;
        }
        for(int i = index; i < n; i++){
            if(index != 0){
                comb(originalString.at(i), currString + ch, n, index + 1, originalString);
            }
            else{
                comb(originalString.at(i), currString, n, index + 1, originalString);
            }
        }

    }
private:
    vector<string> returnValue;
    Permutation2* perm = new Permutation2();
    //string arr[][10]; //= {{"1", "1"},{"2", "ABC"},{"3", "DEF"},{"4", "GHI"},{"5", "JKL"},{"6", "MNO"},{"7", "PQRS"},{"8", "TUV"},{"9", "WXYZ"},{"0", "0"}};
    vector<vector<string>> arr;
};
