#include <iostream>
/*#include "PowerOfNumbers.cpp"
#include "RecursivePalindromeCheck.cpp"
#include "RopeCutting.cpp"*/
 //#include "Subsets.cpp"
 #include "DigitalRoot.h"
#include <vector>

using namespace std;

int main(){

    /*PowerOfNumbers pon;
    cout << pon.power(2, 2) << endl;
    RecursivePalindromeCheck rpc;
    cout << rpc.isPalindrome("boob") << rpc.isPalindrome("bool") << rpc.isPalindrome("malayalam") << endl;*/

    /*vector<int> lengths{12,9,11};
    RopeCutting rc;
    cout << rc.cutRope(23, lengths) << endl;*/
    /*Subsets subsets;
    subsets.calculateSubset("ABC");
    subsets.displayAllSubsets();
    subsets.subset("ABC", "");*/
    DigitalRoot dr;
    int a[]{10, 5, 2, 3, 6};
    cout << dr.calculateSubsetSum(a);
    return 0;
}
