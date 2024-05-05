#include <iostream>
#include <string>
#include <vector>
#include "LongestPalindromicSubstring.cpp"
#include "GenerateParantheses.cpp"
#include "Kadane.cpp"
#include "LCS.cpp"

using namespace std;

int main(){
    //LongestPalindromicSubstring lps;

    //cout << lps.longestPalindrome("aaaaa") << endl;
    //GenerateParantheses gp;
    //vector<string> vec = gp.generateParenthesis(5);
    //int x = gp.longestValidParentheses("()");
    int arr[6] = {5, -2, -3, 32, -5, 65};
    int arr2[5] = {-9, -8, 8, 11, 7};
    int arr3[5] = {-9,-8,8,3,-4};
    //Kadane k;
    //cout << k.maximumSum(arr, 6) <<endl;
    //cout << k.maximumSum(arr2, 5) <<endl;
    //cout << k.maximumSum(arr3, 5) <<endl;

    LCS lcs;
    cout << lcs.lcs(6, 13, "CECDBB", "CAACDDABBDACA") << endl;
    return 0;
}
