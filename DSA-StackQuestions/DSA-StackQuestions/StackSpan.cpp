#include <stack>
#include <vector>

using namespace std;

class StackSpan{
    public:
    //Function to calculate the span of stock’s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> results;
       vector<int> returnValue;

       for(int i =  0; i < n; i++){
           returnValue.push_back(this->calculate(results, price[i]));
           results.push(price[i]);
       }
       return returnValue;
    }
    int calculate(stack<int> results, int x){
        int value = 1;
        while(!results.empty()){
            if(results.top() <= x){
                value++;
                results.pop();
            }
            else{
                break;
            }
        }
        return value;
    }
};

