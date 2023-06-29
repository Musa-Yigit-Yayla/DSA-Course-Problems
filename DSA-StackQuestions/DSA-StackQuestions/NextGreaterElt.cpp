#include <vector>
#include <stack>

using namespace std;
class NextGreaterElt{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement2(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        stack<long long> results;
        for(int i = n - 1; i >= 0; i--){
            long long curr = this->calculate(s, arr.at(i));
            results.push(curr);
            s.push(arr.at(i));
        }

        vector<long long> returnValue;
        while(!results.empty()){
            returnValue.push_back(results.top());
            results.pop();
        }
        return returnValue;
    }
    long long calculate(stack<long long> s, long long x){
        int result = -1;
        while(!s.empty()){
            if(s.top() > x){
                result = s.top();
                break;
            }
            else{
                s.pop();
            }
        }
        return result;
    }
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> s;
        vector<long long> results;
        int i = n - 1;
        while(i >= 0){
            if(s.empty()){
                results.push_back(-1);
                s.push(arr.at(i));
                i--;
                continue;
            }
            while(s.top() <= arr.at(i)){
                s.pop();
            }
            if(!s.empty()){
                results.push_back(s.top());
            }
            else{
                results.push_back(-1);
            }
            s.push(arr.at(i));
            i--;
        }
        //reverse results then return
        for(int i = 0; i < results.size() / 2; i++){
            long long temp = results.at(i);
            results.at(i) = results.at(results.size() - 1 - i);
            results.at(results.size() - 1 - i) = temp;
        }
        return results;
    }
};

