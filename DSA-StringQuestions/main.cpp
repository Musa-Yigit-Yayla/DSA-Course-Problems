#include <iostream>
#include "CheckForRotations.cpp"
#include "IsomorphicString.cpp"
#include "CaseSpecificStringSort.cpp"
#include "AnagramStrings.cpp"

using namespace std;

int main(){
    /*CheckForRotations cfr;

    string s1 = "ababaaaaaa";
    string s2 = "abaa";
    cout << cfr.strstr(s1, s2) << endl;
    cout << cfr.substr(s1, s2) << endl;

    IsomorphicString is;
    string s3 = "wfca";
    string s4 = "yssy";
    cout << is.areIsomorphic(s3, s4) << endl;*/

    caseSpecificStringSort csss;
    string s5 = "defRTSersUXI";
    cout << csss.caseSort(s5) << endl;

    AnagramStrings as;
    string s6 = "geeksforgeeks";
    string s7 = "forgeeksgeeks";
    cout << as.isAnagram(s6, s7) << endl;

    return 0;
}
