#include <iostream>
#include "CheckForRotations.cpp"
#include "IsomorphicString.cpp"

using namespace std;

int main(){
    CheckForRotations cfr;

    string s1 = "ababaaaaaa";
    string s2 = "abaa";
    cout << cfr.strstr(s1, s2) << endl;
    cout << cfr.substr(s1, s2) << endl;

    IsomorphicString is;
    string s3 = "wfca";
    string s4 = "yssy";
    cout << is.areIsomorphic(s3, s4) << endl;

    return 0;
}
