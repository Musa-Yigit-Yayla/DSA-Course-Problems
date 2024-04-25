#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class GenerateParantheses{
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        unordered_map<string, bool> tableDP;
        //we will proceed with a bottom up approach
        tableDP.insert(make_pair("()", true));
        tableDP.insert(make_pair("()()", true));
        tableDP.insert(make_pair("(())", true));
        if(n == 1){
            result.push_back("()");
        }
        else if(n == 2){
            result.push_back("()()");
            result.push_back("(())");
        }
        else{
            //we can start our calculations from n 3
            for(int i = 3; i <= n; i++){
                //fetch all permutations of parantheses strings of length i
                //first retrieve parantheses strings of length i - 1 from tableDP and store them in a vector
                vector<string> prevElts;
                int prevLength = (i - 1) * 2;
                for(auto& it: tableDP){
                    if(it.first.size() == prevLength){
                        prevElts.push_back(it.first);
                    }
                }
                unordered_set<string> currElts = this->permute(prevElts);

                for(unordered_set<string>::iterator it = currElts.begin(); it != currElts.end(); it++){
                if(i == n){
                        //simply fill the result vector since this is the desired level
                        result.push_back(*it);
                }
                else{//track intermediate results
                        tableDP.insert(make_pair(*it, true));
                }
                }

            }
        }
        return result;
    }
    int longestValidParentheses(string s) {
        //we can work with tabulation by using hashmap to store smaller subproblems (substrings) which yields a valid parantheses match
        int result = 0;
        for(int i = 2; i <= s.size(); i += 2){
            string currStr;
            for(int j = 0; j <= s.size() - i; j++){
                currStr = s.substr(j, i); //i represents length, j is the start index
                if(this->validate(currStr)){
                    result = i;
                    break; //no need to search for same length substrings
                }
            }
        }
        return result;
    }
    //Validates whether a given string consists of well formed parantheses
    bool validate(string str){
        stack<char> s;
        for(int i = 0; i < str.size(); i++){
            char curr = str.at(i);
            if(curr == ')'){
                //if the top element is '(', then pop it and we have a match
                if(s.empty()){
                    return false; //not possible to be valid
                }
                else{
                    if(s.top() == '('){
                        s.pop();
                    }
                }
            }
            else if(curr == '('){
                s.push(curr);
            }
        }
        return s.empty(); //if the stack is empty, we have well formed parantheses in our string
    }
    //prevElements are the valid strings containing n - 1 matching parantheses
    unordered_set<string> permute(vector<string>& prevElements){
        unordered_set<string> result;
        for(string s: prevElements){
            for(int i = 0; i <= s.size(); i++){
                string newStr = s.substr(0, i) + '(' + s.substr(i);
                for(int j = i + 1; j < newStr.size(); j++){
                    string tempStr = newStr;
                    tempStr = tempStr.substr(0, j) + ')' + tempStr.substr(j);
                    result.insert(tempStr);
                }
            }
        }
        return result;
    }
};
