#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string generateLine();

int main(){

    long long counter = 0;
    while(counter < 100000000){
        string s = generateLine();
        cout << s << endl;
        counter++;
    }
    return 0;
}
string generateLine(){
    string s = "";
    for(int i = 0; i < 100; i++){
        int value = rand() % 15;
        if(value <= 13){
            s += " ";
        }
        else{
            s += "1";
        }
    }
    return s;
}
