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
        bool currSequenceBroken = false;
        long long overallMin = currMin; // the most minimum element we have encountered so far
        int counter = 0;
        s.pop();
        while(!s.empty()){
            if(s.top() < overallMin){
                overallMin = s.top();
            }
            long long minOfRecents = this->min(prev, s.top()); // minimum of latest two elements
            if(minOfRecents * 2 > prevArea || s.top() > prevArea){
                if(s.top() >= minOfRecents * 2){
                    prevArea = s.top();
                    currMin = s.top();
                    currLength = 1;
                }
                else{
                    prevArea = minOfRecents * 2;
                    currMin = minOfRecents;
                    currLength = 2;
                }
                currSequenceBroken = false;
            }
            else{
                if(s.top() >= currMin && !currSequenceBroken){
                    prevArea += currMin;
                    currLength++;
                }
                else if(s.top() <= overallMin){
                    long long newArea = (counter + 1) * s.top();
                    if(newArea > prevArea){
                        prevArea = newArea;
                        currLength = counter + 1;
                        currMin = s.top();
                        currSequenceBroken = false;
                    }
                }
                else{
                    currSequenceBroken = true;
                }
            }
            counter++;
            prev = s.top();
            s.pop();
        }
        if(n * overallMin > prevArea){
            prevArea = overallMin;
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
