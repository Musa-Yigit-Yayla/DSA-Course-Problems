#include <iostream>
//#include "GetMinAtPop.cpp"
//#include "MaximumRectangularArea.cpp"
#include "MaxOfMin.cpp"
#include <vector>
#include <stack>

using namespace std;
int min = 0;
//Function to push all the elements into the stack.
    stack<int>_push(int arr[],int n)
    {
       // your code here
       stack<int> s;

       s.push(arr[0]);
       ::min = arr[0];
       for(int i = 1; i < n; i++){
           if(arr[i] <= ::min){
               //s.push(2 * arr[i] - ::min);
               s.push(arr[i]);
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
    int getCurrMin(stack<int> s){
        vector<int> arr;
        stack<int> stack;

        int minimum = s.top();
        while(!s.empty()){
            int curr = s.top();


            if(curr < minimum){
                minimum = curr;
            }
            else if(curr == minimum && !s.empty()){
                minimum = s.top();
            }
            arr.push_back(curr);
            s.pop();
        }
        //reverse the array then convert the array into stack from then switch references

        int low = 0, high = arr.size() - 1;
        while(low < high){
            int temp = arr.at(low);
            arr.at(low) = high;
            arr.at(high) = temp;
            low++;
            high--;
        }
        /*for(int i = arr.size() - 1; i >= 0; i--){
            stack.push(arr.at(i));
        }*/
        //s = stack;
        return minimum;
    }
    void _getMinAtPop(stack<int> s)
    {
        // your code here
        while(!s.empty()){
            cout << ::min << " ";
            int curr = s.top();
            //int minimum = min; //for debugging purposes
            s.pop();
            if(curr < ::min){
                //::min = 2 * ::min - curr;
                ::min = curr;
            }
            else if(curr == ::min && !s.empty()){
                ::min = getCurrMin(s);
            }

        }
        cout << endl;
    }
int main()
{
    //GetMinAtPop gmap;
    //int arr[12] = {20, 59, 42, 94, 12, 46, 51, 40, 67, 41, 7, 56};
    //stack<int> newStack = _push(arr, 12);
    //gmap._getMinAtPop(newStack);
    //_getMinAtPop(newStack);
    /*MaximumRectangularArea mra;
    int n = 5;
    long long arr[n] =  {5, 4, 3, 2, 1};
    long long arr1[10] = {10,9,8,7,6,1,2,3,4,5};
    cout << mra.getMaxArea(arr1, 10) << endl;*/
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = 7;
    MaxOfMin mom;
    vector<int> result = mom.maxOfMin(arr, n);
    return 0;
}
