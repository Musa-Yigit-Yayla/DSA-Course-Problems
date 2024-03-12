#include <iostream>
#include <vector>
#include "SortQuicker.cpp"

using namespace std;

void printVec(vector<int>&);

int main(){
        vector<int> vec = {5, 6, 4, 3, 8, 12, 45, 9, 2, 1};
        vector<int> vec2 = {5, 4, 3, 2, 1};
        SortQuick sq;
        sq.sortArray(vec);
        printVec(vec);
        sq.sortArray(vec2);
        printVec(vec2);

        return 0;
}

void printVec(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec.at(i) << ", ";
    }
    cout <<endl;
}
