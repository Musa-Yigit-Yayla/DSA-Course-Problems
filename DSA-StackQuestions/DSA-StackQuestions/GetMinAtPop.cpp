#include <stack>

using namespace std;
class GetMinAtPop{
public:
    //Function to push all the elements into the stack.
    stack<int>_push(int arr[],int n)
    {
       // your code here
       stack<int> s;

       s.push(arr[0]);
       ::min = arr[0];
       for(int i = 1; i < n; i++){
           if(arr[i] <= ::min){
               s.push(2 * arr[i] - ::min);
               ::min = arr[i];
           }
           else{
               s.push(arr[i]);
           }
       }
       return s;
    }

    /* print minimum element of the stack each time
       after poppings
    */
    int getCurrMin(stack<int>& s){
        int min = INT_MAX;
        vector<int> arr;
        stack<int> stack;

        while(!s.empty()){
            int curr = s.top();
            s.pop();
            arr.push_back(curr);
            if(curr < min){
                min = curr;
            }
        }
        //reverse the array then convert the array into stack from then switch references

        int low = 0, high = arr.size() - 1;
        /*while(low < high){
            int temp = arr.at(low);
            arr.at(low) = high;
            arr.at(high) = low;
            low++;
            high--;
        }*/
        for(int i = arr.size() - 1; i >= 0; i--){
            stack.push(arr.at(i));
        }
        s = stack;
        return min;
    }
    void _getMinAtPop(stack<int>s)
    {
        // your code here
        while(!s.empty()){
            cout << ::min << " ";
            int curr = s.top();
            if(curr <= ::min){
                ::min = 2 * ::min - curr;
            }
            s.pop();
        }
        cout << endl;
    }
};
