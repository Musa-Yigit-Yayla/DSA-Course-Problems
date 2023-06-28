#include <stack>

using namespace std;

class DeleteMid{
    public:
    //Function to delete middle element of a stack.
    void reverseStack(stack<int>& s){
        stack<int> copy;
        while(!s.empty()){
            copy.push(s.top());
            s.pop();
        }
        s = copy;
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        const int mid = sizeOfStack / 2;
        stack<int> temp;
        for(int i = 0; i < mid; i++){
            temp.push(s.top());
            s.pop();
        }
        s.pop();
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
};
