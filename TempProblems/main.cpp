#include <iostream>
#include <vector>
#include "SortQuicker.cpp"
#include "HIndex.cpp"
#include "FindShiftAmt.cpp"

using namespace std;

void printVec(vector<int>&);

int main(){
        vector<int> vec = {5, 6, 4, 3, 8, 12, 45, 9, 2, 1};
        vector<int> vec2 = {5, 4, 3, 2, 1};
        vector<int> vec1 = {1, 2, 2 ,1};
        /*SortQuick sq;
        sq.sortArray(vec);
        printVec(vec);
        sq.sortArray(vec2);
        printVec(vec2);*/
        HIndex hi;
        hi.hIndex(vec1);
        FindShiftAmt fsa;
        vector<int> vec3 = {35, 42, 5, 15, 27, 29};
        vector<int> vec4 = {27, 29, 35, 42, 5, 15};
        vector<int> vec5 = {3, 5, 5, 2, 2};
        vector<int> vec6 = {1, 2, 3, 4, 5};
        vector<int> vec7 = {15, 3, 4};
        vector<int> vec8 = {14, 15, 16, 17, 19, -20};

        cout << "Vec3: " << fsa.findShift(vec3) << endl;
         cout << "Vec4: " << fsa.findShift(vec4) << endl;
          cout << "Vec5: " << fsa.findShift(vec5) << endl;
           cout << "Vec6: " << fsa.findShift(vec6) << endl;
           cout << "Vec7: " << fsa.findShift(vec7) << endl;
            cout << "Vec8: " << fsa.findShift(vec8) << endl;

        return 0;
}

void printVec(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec.at(i) << ", ";
    }
    cout <<endl;
}
