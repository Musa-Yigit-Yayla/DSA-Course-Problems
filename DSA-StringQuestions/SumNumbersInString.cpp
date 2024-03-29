#include "ctype.h"
#include <vector>
#include <string>

using namespace std;
class SumNumbersInString{
public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str){
    	// Your code here
    	int sum = 0;

    	vector<int> nums = parseNumbers(str);
    	for(int i = 0; i < nums.size(); i++){
    	    sum += nums.at(i);
    	}
    	return sum;
    }
    vector<int> parseNumbers(string& str){
        vector<int> nums;

        string num = "";
        for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(isdigit(ch)){
                num += ch;
            }
            else if(num.size() != 0){
                nums.push_back(stoi(num));
                num = "";
            }
        }
        //After the loop, check whether the current num is a number or not
        bool isNum = true;
        for(int i = 0; i < num.size(); i++){
            char ch = num.at(i);
            if(!isdigit(ch)){
                isNum = false;
                break;
            }
        }
        if(isNum && num.size() != 0){
            nums.push_back(stoi(num));
        }
        return nums;
    }
    //Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) {
    	// Your code here
    	for(int i = 0; i < txt.size() - pat.size(); i++){
    	    int index = 0; //index for accomplishing the comparison
    	    bool found = true;
    	    for(int j = i; j <= i + pat.size(); j++){
    	        if(txt.at(j) != pat.at(index++)){
    	            found = false;
    	            break;
    	        }
    	    }
    	    if(found){
    	        return true;
    	    }
    	}
    	return false;
    }
};
