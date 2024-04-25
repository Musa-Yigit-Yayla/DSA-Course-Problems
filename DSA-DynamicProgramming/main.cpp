#include <iostream>
#include <string>
#include <vector>
#include "LongestPalindromicSubstring.cpp"
#include "GenerateParantheses.cpp"

using namespace std;

int main(){
    //LongestPalindromicSubstring lps;

    //cout << lps.longestPalindrome("aaaaa") << endl;
    GenerateParantheses gp;
    vector<string> vec = gp.generateParenthesis(5);
    return 0;
}
