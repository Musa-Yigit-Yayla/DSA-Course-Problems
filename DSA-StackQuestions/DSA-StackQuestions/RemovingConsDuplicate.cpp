#include <stack>
#include <string>

using namespace std;
class RemovingConsDuplicate{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string x)
    {
        // Your code here
        stack<char> s;
        for(int i = x.size() - 1; i >= 0; i--){
            s.push(x.at(i));
        }
        //reverseStack(s);
        string result = "";
        char* prev = nullptr;
        while(!s.empty()){
            if(prev == NULL){
                prev = &s.top();
            }
            else{
                if(*prev != s.top()){
                    result += *prev;
                    prev = &s.top();
                }
                s.pop();
            }
        }
        result += *prev;
        return result;
    }
    void reverseStack(stack<char>& s){
        stack<char> copy;
        while(!s.empty()){
            copy.push(s.top());
            s.pop();
        }
        s = copy;
    }
    string removePair(string str){
        // Your code here
        stack<char> chars;
        for(int i = str.size() - 1; i >= 0; i--){
            if(!chars.empty()){
                char prev = chars.top();
                if(prev == str.at(i)){
                    chars.pop();
                }
                else{
                    chars.push(str.at(i));
                }
            }
            else{
                chars.push(str.at(i));
            }
        }
        //convert stack into string, the top element will be 0 indexed on our newly instantiated string
        string result = "";
        while(!chars.empty()){
            result += chars.top();
            chars.pop();
        }
        return result;
    }
};
