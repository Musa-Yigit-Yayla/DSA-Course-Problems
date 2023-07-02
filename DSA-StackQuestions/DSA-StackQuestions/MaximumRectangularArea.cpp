#include <stack>

using namespace std;
class MaximumRectangularArea{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> s = this->getStack(arr, n);
        long long prevArea = s.top();
        long long currLength = 1;
        long long currMin = s.top();
        long long prev = s.top();
        s.pop();
        while(!s.empty()){
            long long minOfRecents = this->min(prev, s.top()); // minimum of latest two elements
            if(minOfRecents * 2 > prevArea){
                prevArea = minOfRecents * 2;
                currMin = minOfRecents;
                currLength = 2;
            }
            else{
                if(s.top() >= currMin){
                    prevArea += currMin;
                    currLength++;
                }
                else{
                    long long newArea = (currLength + 1) * s.top();
                    if(newArea > prevArea){
                        prevArea = newArea;
                        currLength++;
                        currMin = s.top();
                    }
                }
            }
            prev = s.top();
            s.pop();
        }
        return prevArea;
    }
    stack<long long> getStack(long long arr[], int n){
        stack<long long> s;
        for(int i = 0; i < n; i++){
            s.push(arr[i]);
        }
        return s;
    }
    long long min(const long long a, const long long b){
        if(a < b){
            return a;
        }
        else{
            return b;
        }
    }
};
