#include <iostream>
#include <string>
#include <vector>
#include "LongestPalindromicSubstring.cpp"
#include "GenerateParantheses.cpp"
#include "Kadane.cpp"

using namespace std;

int main(){
    //LongestPalindromicSubstring lps;

    //cout << lps.longestPalindrome("aaaaa") << endl;
    //GenerateParantheses gp;
    //vector<string> vec = gp.generateParenthesis(5);
    //int x = gp.longestValidParentheses("()");
    int arr[6] = {5, -2, -3, 32, -5, 65};
    Kadane k;
    cout << k.maximumSum(arr, 6) <<endl;
    return 0;
}
