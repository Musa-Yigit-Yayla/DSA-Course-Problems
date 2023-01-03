#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Subsets{
    //ABC
private:
    vector<string> subsets;
public:
    void calculateSubset(string s){
        vector<int> usedIndexes;
        calculateSubsetHelper(s, usedIndexes, "");
    }
    /*
        @s original string
        @ usedIndexes indexes already used from the s
        @ currString string comprised of usedIndexes chars
    */
    void calculateSubsetHelper(string s, vector<int> usedIndexes, string currString){
        //generate randIndex which is not in the usedIndexes
        for(int i = 0; i < s.length(); i++){
            if(count(usedIndexes.begin(), usedIndexes.end(), i) != 0){
                //if the index is already used
                continue;
            }
            if(currString != ""){
                //add the currString to solutions
                subsets.push_back(currString);
            }
            vector<int> copyVec = vectorCopier(usedIndexes);
            copyVec.push_back(i);
            calculateSubsetHelper(s, copyVec, currString + s.at(i));
        }
    }
    void subset(string s, string curr, int i = 0){
        if(i == s.length()){
            //base case
            cout << curr;
        }
        subset(s, curr, i + 1);
        subset(s, curr + s.at(i), i + 1);
    }
    vector<int> vectorCopier(vector<int> original){
        vector<int> copyVec;
        for(int i = 0; i < original.size(); i++){
            int curr = original.at(i);
            copyVec.push_back(curr);
        }
        return copyVec;
    }
    //Invoke after calculations
    void displayAllSubsets(){
        for(int i = 0; i < this->subsets.size(); i++){
            string curr = subsets.at(i);
            cout << curr << " ";
        }
    }
};
