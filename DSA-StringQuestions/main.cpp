#include <iostream>
#include "CheckForRotations.cpp"

using namespace std;

int main(){
    CheckForRotations cfr;

    string s1 = "ababaaaaaa";
    string s2 = "abaa";
    cout << cfr.strstr(s1, s2) << endl;
    cout << cfr.substr(s1, s2) << endl;

    return 0;
}
