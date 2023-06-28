#include <string>
#include <stack>

using namespace std;
class ParanthesisChecker{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        if(x.size() == 1 || !isNumericallyBalanced(x)){
            return false;
        }
        stack<char> s;
        //bool hasEntered2 = false;
        //bool hasEntered3 = false;
        for(int i = 0; i < x.size(); i++){
            char ch = x.at(i);
            if(ch == '{' || ch == '[' || ch == '('){
                s.push(ch);
            }
            else if(!s.empty() && (ch == '}' || ch == ']' || ch == ')')){
                //if(hasEntered2){
                  //  hasEntered3 = true;
                //}
                //hasEntered2 = true;
                char topElt = s.top();
                switch(topElt){
                    case '(':
                        if(ch == ')')
                            s.pop();
                        else
                            return false;
                    break;
                    case '[':
                        if(ch == ']')
                            s.pop();
                        else
                            return false;
                    break;
                    case '{':
                        if(ch == '}')
                            s.pop();
                        else
                            return false;
                    break;
                    default:
                        return false; break;
                }
            }
        }
        return s.empty();
    }
    //checks whether the string contains the chars we desire and opening and closing bracket types and
    //occurence counts do actually match
    static bool isNumericallyBalanced(string s){
        if(s.size() % 2 == 1){
            return false;
        }
        int bracketArr[2] = {0, 0}; // ()
        int currlyArr[2] = {0, 0}; // {}
        int arrayBracket[2] = {0, 0}; // []

        for(int i = 0; i < s.size(); i++){
            switch(s.at(i)){
                case '(': bracketArr[0]++; break;
                case ')': bracketArr[1]++; break;
                case '{': currlyArr[0]++; break;
                case '}': currlyArr[1]++; break;
                case '[': arrayBracket[0]++; break;
                case ']': arrayBracket[1]++; break;
                default: return false;
            }
        }
        return bracketArr[0] == bracketArr[1] && currlyArr[0] == currlyArr[1] && arrayBracket[0] ==arrayBracket[1];
    }
};
