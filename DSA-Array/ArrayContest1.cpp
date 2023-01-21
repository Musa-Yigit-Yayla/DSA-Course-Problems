#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class ArrayContest1{
    static int q1(int n){
        int res = 0;
        while(n != 1){
            if(n % 2 == 0){
                n /= 2;
                res++;
            }
            else{
                if(n <= 0){
                    n++;
                    res++;
                }
                else{
                    n--;
                    res++;

                }
            }
        }
        return res;
    }
    static void q2(vector<int>& arr, int n){
        int b;
        int e; // b missing e most occuring
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.at(n - 1); i++){
            if(count(arr.begin(), arr.end(), i) == 0){
                b = i;
                break;
            }
        }
        int occurenceCount = 1;
        int maxOccurenceCount = 1;
        int maxOccurentElt = arr.at(0);
        int elt = arr.at(0);
        for(int i = 1; i < arr.size(); i++){

            if(arr.at(i) == elt){
                occurenceCount++;
                if(occurenceCount > maxOccurenceCount){
                    maxOccurenceCount = occurenceCount;
                    maxOccurentElt = elt;
                }
            }
            else{
                occurenceCount = 1;
                elt = arr.at(i);
            }
        }
        e = maxOccurentElt;
        cout << b << " " << e << endl;
    }
};
