//maximum of minimum for every window size
//Musa Yiğit Yayla

#include <stack>
#include <vector>

using namespace std;
class MaxOfMin{
public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        stack<int> s;
        //initialize the stack
        /*for(int i = 0; i < n; i++){
            s.push(arr[i]);
        }*/

        int left[n + 1];
        int right[n + 1];
        for(int i = 0; i < n; i++){
            left[i] = -1;
            right[i] = n;
        }
        for(int i = 0; i < n; i++){
            //int curr = arr[i];
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top();
            }
            s.push(i);
        }
        //empty the stack
        while(!s.empty()){
            s.pop();
        }
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                right[i] = s.top();
            }
            s.push(i);
        }
        vector<int> result;
        for(int i = 0; i < n + 1; i++){
            result.push_back(0);
        }
        for(int i = 0; i < n; i++){
            int len = right[i] - left[i] - 1;
            result.at(len) = max(result.at(len), arr[i]);
        }
        for(int i = n - 1; i >= 1; i--){
            result.at(i) = max(result.at(i + 1), result.at(i));
        }
        result.erase(result.begin());

        return result;
    }
};
