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
    static int q3(int n){
        int distance = min(n - floor(sqrt(n)), ceil(sqrt(n)) - n);
    if(distance == n - floor(sqrt(n))){
        return floor(sqrt(n));
    }
    else{
        return ceil(sqrt(n));
    }
    }
    static int fun (int n)
{
  int x = 1;
  if (n == 1 ){
    return x;
  }
  for (int k =1 ; k < n; ++k){
     x = x + fun(k) * fun(n - k);
  }
  return x;
}
int q1v2 (int n, int res){

        if(n == 0){
            return res + 1;
        }
        else if(n == 1){
            return res;
        }
        else{
            if(n > 0){

                return min(q1v2(n / 2, res + 1), q1v2(n - 1, res + 1));
            }
            else{
                return min(q1v2(n / 2, res + 1), q1v2(n + 1, res + 1));
            }
        }
}
};
