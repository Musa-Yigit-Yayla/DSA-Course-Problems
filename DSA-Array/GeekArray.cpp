#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class GeekArray{
public:
     //Function to find the days of buying and selling stock for max profit.
    static vector<vector<int>> stockBuySell(vector<int> arr, int n){
        // code here
        vector<vector<int>> result;
        vector<vector<int>> bottoms;
        vector<vector<int>> peaks;
        for(int i = 0; i < n; i++){
            vector<int> currResult; // first element is the value, second is its index
            if(i == 0 && n > 1){
                if(arr.at(0) < arr.at(1)){
                    currResult.push_back(arr.at(0));
                    currResult.push_back(0);
                    bottoms.push_back(currResult);
                }
            }
            else if(i == n - 1){
                if(arr.at(n - 2) > arr.at(i)){
                    currResult.push_back(arr.at(i));
                    currResult.push_back(i);
                    bottoms.push_back(currResult);
                }
                else if(arr.at(n - 2) < arr.at(i)){
                    currResult.push_back(arr.at(i));
                    currResult.push_back(i);
                    peaks.push_back(currResult);
                }
            }
            else{
                //midpoint
                if((arr.at(i - 1) < arr.at(i)) && (arr.at(i) > arr.at(i + 1))){
                    //peak
                    currResult.push_back(arr.at(i));
                    currResult.push_back(i);
                    peaks.push_back(currResult);
                }
                else if(arr.at(i - 1) > arr.at(i) && arr.at(i + 1) > arr.at(i)){
                    currResult.push_back(arr.at(i));
                    currResult.push_back(i);
                    bottoms.push_back(currResult);
                }
            }
        }
        for(int i = 0; i < min(bottoms.size(), peaks.size()); i++){
            vector<int> currResult;
            //retrieve the index
            currResult.push_back(bottoms.at(i).at(1));
            currResult.push_back(peaks.at(i).at(1));
            result.push_back(currResult);
        }

        return result;
    }

};
