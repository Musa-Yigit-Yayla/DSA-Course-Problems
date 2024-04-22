#include <string>

using namespace std;
class LongestPalindromicSubstring {
public:
    string longestPalindrome(string s) {
        //we can use tabulazation as a bottom up approach
        //we can use a 2d bool array to store the subproblem results
        string result = "";
        //int tableLength = s.size() * (s.size() + 1) / 2;
        int tempLength = s.size();
        const int arrLength = *const_cast<const int*>(&tempLength);

        //first initialize the contents
        bool** arr = new bool*[arrLength]; //array contains rowIndex as the start index and columnIndex as the end index (inclusive)
        //of a substring. The result specifies whether the designated substring is palindromic
        for(int i = 0; i < s.size(); i++){
            arr[i] = new bool[arrLength];
            for(int j = 0; j < s.size(); j++){
                arr[i][j] = false;
            }
        }
        //first diagonal is always true since length 1 substrings are palindromic
        for(int i = 0; i < s.size(); i++){
            arr[i][i] = true;
        }
        //also set up the length 2 substring entries if they are palindromic directly for increased efficiency
        for(int i = 1; i < s.size(); i++){
            if(this->isPalindrome(s.substr(i - 1, 2))){
                arr[i - 1][i] = true;
            }
        }
        //instead of traversing in a right to left and top to bottom manner, we should try diagonal traversal to calculate the results correctly
        for(int i = 0; i < s.size(); i++){ //i is the row index
            for(int j = i + 2, k = 0; j < s.size(); j++, k++){ //j is the column index we are interested to calculate
                bool currResult = false;
                //check if the ith and jth characters match each other and if the middle part is palindromic by using the dp table
                if(s.at(k) == s.at(j)){
                    if(k < s.size() - 1 && j > 0){
                        currResult = arr[k + 1][j - 1];
                    }
                    else{
                        currResult = true; //true since the intermediate substring is of length 0
                    }
                }
                arr[k][j] = currResult;
            }
        }
        //now we must search for a largest substring
        //start the iteration from top right and search only the half of the matrix including the main diagonal
        for(int i = 0; i < s.size(); i++){
            for(int j = s.size() - 1; j >= i; j--){
                if(arr[i][j] == true){
                    //we have a palindrome, check if it is of larger length than current result
                    int length = j - i + 1;
                    string currStr = s.substr(i, length);
                    if(currStr.size() > result.size()){
                        result = currStr;
                    }
                }
            }
        }
        //deallocate the 2d array and return the result;
        for(int i = 0; i < s.size(); i++){
            delete arr[i];
        }
        delete[] arr;
        return result;

        /*for(int i = 1; i < s.size(); i++){
            for(int j = 0; j < s.size() - i + 1){
                //from up to j, j + i forms a substring
            }
        }*/
    }
    bool isPalindrome(string s){
        bool result = true;
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s.at(i) != s.at(j)){
                result = false;
                break;
            }
            i++;
            j--;
        }
        return result;
    }
};
