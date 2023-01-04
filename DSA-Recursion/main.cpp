#include <bits/stdc++.h>
#include <vector>
#include <string>
#include "PossibleWordsFromPhoneDigits.cpp"

using namespace std;

int main(){
    PossibleWordsFromPhoneDigits pwfpd;
    int a[3];
    a[0] = 2;
    a[1] = 3;
    a[2] = 4;
    vector<string> result = pwfpd.possibleWords(a, 3);
    for(size_t i = 0; i < result.size(); i++){
        cout << result.at(i) << " ";
    }
    return 0;
}
