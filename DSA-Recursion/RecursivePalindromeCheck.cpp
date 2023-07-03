#include <iostream>
#include <string>
using namespace std;

class RecursivePalindromeCheck{
public:
    bool isPalindrome(string s){
        return isPalindromeHelper(s, 0, s.length() - 1);
    }
    bool isPalindromeHelper(string s, int high, int low){
        char lower = s.at(low);
        char higher = s.at(high);

        if(lower != higher){
            return false;
        }
        else if(high <= low){
            // base case
            return true;
        }
        else{
            return isPalindromeHelper(s, high - 1, low + 1);
        }
    }

};
